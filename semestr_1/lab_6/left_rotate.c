#include <stdio.h>
#include <stdlib.h>
int l = 1;

struct AVL_tree
{
    int key_elem;
    int bal;
    struct AVL_tree *left;
    struct AVL_tree *right;
};

void RLR(struct AVL_tree **node)
{
    struct AVL_tree *rl_node = (*node)->right->left, *temp_right = rl_node->right, *temp_left = rl_node->left;
    rl_node->right = (*node)->right;
    rl_node->left = *node;
    *node = rl_node;
    rl_node->right->left = temp_right;
    rl_node->left->right = temp_left;
}

void RRR(struct AVL_tree **node)
{
    struct AVL_tree *temp = (*node)->right->left;
    (*node)->right->left = *node;
    *node = (*node)->right;
    (*node)->left->right = temp;
}

void LLR(struct AVL_tree **node)
{
    struct AVL_tree *temp = (*node)->left->right;
    (*node)->left->right = *node;
    *node = (*node)->left;
    (*node)->right->left = temp;
}

void LRR(struct AVL_tree **node)
{
    struct AVL_tree *lr_node = (*node)->left->right,
                    *temp_left = lr_node->left,
                    *temp_right = lr_node->right;

    lr_node->left = (*node)->left;
    lr_node->right = *node;
    *node = lr_node;
    lr_node->left->right = temp_left;
    lr_node->right->left = temp_right;
}

void rotate(struct AVL_tree **node)
{
    if ((*node)->bal < 0)
    {
        if ((*node)->left->bal > 0)
        {
            LRR(node);
        }
        else
        {
            LLR(node);
        }
    }
    else if ((*node)->bal > 0)
    {
        if ((*node)->right->bal < 0)
        {
            RLR(node);
        }
        else
        {
            RRR(node);
        }
    }
}

int recover_AVL(struct AVL_tree **parents)
{
    if (*parents == NULL)
        return 0;
    int lt_height = recover_AVL(&(*parents)->left) + 1;
    int rt_height = recover_AVL(&(*parents)->right) + 1;
    (*parents)->bal = rt_height - lt_height;
    if ((*parents)->bal < -1 || (*parents)->bal > 1)
        rotate(parents);
    if (lt_height > rt_height)
        return lt_height;
    else if (lt_height < rt_height)
        return rt_height;
}

int height_count(struct AVL_tree *parents)
{
    if (parents == NULL)
    {
        return 0;
    }
    int lt_height = height_count(parents->left);
    int rt_height = height_count(parents->right);
    return lt_height + rt_height + 1;
}
void out(struct AVL_tree *node)
{

    printf("%d %d %d\n", node->key_elem, (l + 1) * (node->left != NULL), (height_count(node->left) + l + 1) * (node->right != NULL));
    l++;
    if (node->left)
    {
        out(node->left);
    }
    if (node->right)
    {
        out(node->right);
    }
}

int main()
{
    int n, left, right;
    scanf("%d", &n);
    if (n == 0)
    {
        printf("0\n");
        return 0;
    }

    struct AVL_tree ***points = malloc((n + 1) * sizeof(size_t));
    struct AVL_tree *parents, *child;
    points[0] = &child;
    points[1] = &parents;
    for (int i = 1; i <= n; ++i)
    {
        struct AVL_tree *current = malloc(sizeof(struct AVL_tree));
        *points[i] = current;
        scanf("%d %d %d", &current->key_elem, &left, &right);
        points[left] = &current->left;
        points[right] = &current->right;
    }

    recover_AVL(&parents);
    printf("%d\n", n);
    out(parents);
    return 0;
}