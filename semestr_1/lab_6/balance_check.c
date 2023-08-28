#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#define max(a, b) a > b ? a : b

struct AVL_tree
{
    int lt;
    int rt;
    int key_elem;
    int bal;
};

int height_count(struct AVL_tree *arr, int ind)
{
    if (ind == 0)
    {
        return 0;
    }
    long left_height = height_count(arr, arr[ind].lt) + 1;
    long right_height = height_count(arr, arr[ind].rt) + 1;
    arr[ind].bal = right_height - left_height;
    return max(left_height, right_height);
}

int main()
{
    int n;
    scanf("%d", &n);
    if (n == 0)
    {
        printf("0\n");
        return 0;
    }
    struct AVL_tree *arr = malloc((n + 1) * sizeof(struct AVL_tree));
    arr[0].rt = 0;
    arr[0].lt = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d %d %d", &arr[i].key_elem, &arr[i].lt, &arr[i].rt);
    }
    height_count(arr, 1);
    for (int i = 1; i <= n; ++i)
    {
        printf("%d\n", arr[i].bal);
    }

    return 0;
}