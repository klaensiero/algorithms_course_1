#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>
#include <stddef.h>
#define max(a, b) a > b ? a : b

struct AVL_tree
{
    int key_elem;
    int bal;
    struct AVL_tree *lt;
    struct AVL_tree *rt;
    struct AVL_tree *parent;
};

int count_balance(struct AVL_tree *parent)
{
    if (parent == NULL)
        return 0;
    int lt_height = count_balance(parent->lt) + 1;
    int rt_height = count_balance(parent->rt) + 1;
    parent->bal = rt_height - lt_height;
    return max(lt_height, rt_height);
}

void LLR(struct AVL_tree **node)
{
    struct AVL_tree *temp = (*node)->lt->rt;
    (*node)->lt->rt = *node;
    *node = (*node)->lt;
    (*node)->rt->lt = temp;
}

void LRR(struct AVL_tree **node)
{

    struct AVL_tree *lr_node = (*node)->lt->rt,
                    *left_temp = lr_node->lt,
                    *right_temp = lr_node->rt;

    lr_node->lt = (*node)->lt;
    lr_node->rt = *node;
    *node = lr_node;
    lr_node->lt->rt = left_temp;
    lr_node->rt->lt = right_temp;
}

void RLR(struct AVL_tree **node)
{
    struct AVL_tree *rl_node = (*node)->rt->lt,
                    *right_temp = rl_node->rt,
                    *left_temp = rl_node->lt;
    rl_node->rt = (*node)->rt;
    rl_node->lt = *node;
    *node = rl_node;
    rl_node->rt->lt = right_temp;
    rl_node->lt->rt = left_temp;
}

void RRR(struct AVL_tree **node)
{
    struct AVL_tree *temp = (*node)->rt->lt;
    (*node)->rt->lt = *node;
    *node = (*node)->rt;
    (*node)->lt->rt = temp;
}

void rotate(struct AVL_tree **node)
{
    if ((*node)->bal < 0)
    {
        if ((*node)->lt->bal > 0)
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
        if ((*node)->rt->bal < 0)
        {
            RLR(node);
        }
        else
        {
            RRR(node);
        }
    }
}

int rebalance(struct AVL_tree **parent)
{
    if (*parent == NULL)
        return 0;
    int lt_height = rebalance(&(*parent)->lt) + 1;
    int rt_height = rebalance(&(*parent)->rt) + 1;
    (*parent)->bal = rt_height - lt_height;
    if ((*parent)->bal < -1 or (*parent)->bal > 1)
    {
        rotate(parent);
        lt_height = count_balance((*parent)->lt) + 1;
        rt_height = count_balance((*parent)->rt) + 1;
        (*parent)->bal = rt_height - lt_height;
    }
    return max(lt_height, rt_height);
}

void insert(struct AVL_tree **node, int elem)
{
    struct AVL_tree *parent = NULL;
    while (*node != NULL and (*node)->key_elem != elem)
    {
        parent = *node;

        if (elem > (*node)->key_elem)
        {
            node = &(*node)->rt;
        }
        else if (elem < (*node)->key_elem)
        {
            node = &(*node)->lt;
        }
    }

    if (*node != NULL)
    {
        return;
    }

    *node = malloc(sizeof(struct AVL_tree));
    (*node)->key_elem = elem;
    (*node)->parent = parent;
    (*node)->lt = NULL;
    (*node)->rt = NULL;
}

int count(struct AVL_tree *parent)
{
    if (parent == NULL)
    {
        return 0;
    }
    int lt_height = count(parent->lt);
    int rt_height = count(parent->rt);
    return lt_height + rt_height + 1;
}

void out(struct AVL_tree *node)
{
    static int l = 1;
    printf("%d %d %d\n", node->key_elem,
           (l + 1) * (node->lt != NULL),
           (count(node->lt) + l + 1) * (node->rt != NULL));
    l += 1;
    if (node->lt)
    {
        out(node->lt);
    }
    if (node->rt)
    {
        out(node->rt);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    if (n == 0)
    {
        int elem;
        scanf("%d", &elem);
        printf("1\n%d 0 0\n", elem);
        return 0;
    }
    struct AVL_tree ***points = malloc((n + 1) * sizeof(size_t));
    struct AVL_tree *parent, *child;
    points[0] = &child;
    points[1] = &parent;
    for (int i = 1; i <= n; ++i)
    {
        int lt, rt;
        struct AVL_tree *cur = malloc(sizeof(struct AVL_tree));
        *points[i] = cur;
        scanf("%d %d %d", &cur->key_elem, &lt, &rt);
        points[lt] = &cur->lt;
        *points[0] = NULL;
        points[rt] = &cur->rt;
        *points[0] = NULL;
    }

    free(points);
    int elem;
    scanf("%d", &elem);
    insert(&parent, elem);
    rebalance(&parent);
    printf("%d\n", n + 1);
    out(parent);
    
    return 0;
}