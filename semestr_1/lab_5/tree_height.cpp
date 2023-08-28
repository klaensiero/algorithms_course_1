#include <bits/stdc++.h>
using namespace std;

int func(vector<pair<int, int>> &bst, int ps)
{
    int l = 0;
    int r = 0;
    if (bst[ps].first > -1)
    {
        l = func(bst, bst[ps].first);
    }
    if (bst[ps].second > -1)
    {
        r = func(bst, bst[ps].second);
    }
    return max(l, r) + 1;
}
int main()
{
    int n, el, el1, el2;
    cin >> n;
    if (n != 0)
    {
        vector<pair<int, int>> t(n);
        for (int i = 0; i < n; i++)
        {
            cin >> el >> el1 >> el2;
            t[i] = make_pair(el1 - 1, el2 - 1);
        }
        int res = func(t, 0);
        cout << res << "\n";
    }

    else
    {
        cout << 0 << "\n";
        return 0;
    }

    return 0;
}