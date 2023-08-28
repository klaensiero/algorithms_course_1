#include <bits/stdc++.h>
using namespace std;

void func(vector<long long> &arr, int n, int min, int max, int &ind)
{
    if ((arr[ind] > max) or (arr[ind] < min))
    {
        return;
    }
    if (ind == n)
    {
        return;
    }

    int elem = arr[ind];
    ind += 1;
    func(arr, n, min, elem, ind);
    func(arr, n, elem, max, ind);
    cout << elem << " ";
}

void funcs(vector<long long> &arr, int n)
{
    int ind = 0;
    func(arr, n, -1000000000, 1000000000, ind);
}

int main()
{
    vector<long long> mass;
    int n, elem;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> elem;
        mass.push_back(elem);
    }

    funcs(mass, n);
    cout << "\n";

    return 0;
}