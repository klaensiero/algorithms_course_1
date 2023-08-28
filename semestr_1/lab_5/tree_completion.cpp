#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>
using namespace std;

typedef struct Tree_bst
{
    vector<int> root;
    vector<int> lt;
    vector<int> rt;
    explicit Tree_bst(int n)
    {
        lt = vector<int>(n);
        rt = vector<int>(n);
        root = vector<int>(n);
    }
} Tree_bst;

void func(Tree_bst *bst, vector<int> *res, int n, int *j)
{
    if (n > -1)
    {
        func(bst, res, bst->lt.at(n), j);
        res->at(n) = ++*j;
        func(bst, res, bst->rt.at(n), j);
    }
}

int main()
{
    int n, l, r, j = 0;
    cin >> n;
    vector<int> res(n);
    Tree_bst bst(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> l >> r;
        bst.rt.at(i) = r - 1;
        bst.lt.at(i) = l - 1;
        if (r > 0)
            bst.root.at(r - 1) = i;
        else if (l > 0)
            bst.root.at(l - 1) = i;
    }
    func(&bst, &res, 0, &j);
    
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << " ";
    
    cout << "\n";
    
    return 0;
}