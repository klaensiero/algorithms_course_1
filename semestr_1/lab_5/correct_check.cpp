#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>
using namespace std;

typedef struct Tree_bst
{
    int k;
    int l;
    int r;
} Tree_bst;

bool check_bst(Tree_bst *bst, int ps, int min, int max)
{
    bool check = true;
    if ((bst[ps].k <= min) or (bst[ps].k >= max))
        return false;
    if (bst[ps].l > 0 and check)
        return check_bst(bst, bst[ps].l - 1, min, bst[ps].k);
    if (bst[ps].r > 0 and check)
        return check_bst(bst, bst[ps].r - 1, bst[ps].k, max);
    return check;
}

int main()
{
    bool check;
    int n;
    cin >> n;
    Tree_bst bst[n];
    if (n == 0)
    {
        cout << "YES"
             << "\n";
        return 0;
    }
    for (int i = 0; i < n; ++i)
        cin >> bst[i].k >> bst[i].l >> bst[i].r;
    check = check_bst(bst, 0, -1000000000, 1000000000);
    if (check)
        cout << "YES"
             << "\n";
    else
        cout << "NO"
             << "\n";
             
    return 0;
}