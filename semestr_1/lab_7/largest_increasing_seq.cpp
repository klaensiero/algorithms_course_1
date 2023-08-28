#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100000;

int n;
int a[N];
int dp[N];
int par[N];

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        par[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                par[i] = j;
            }
        }
    }

    int max_len = 0, index = -1;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] > max_len)
        {
            max_len = dp[i];
            index = i;
        }
    }

    cout << max_len << "\n";
    int cur = index;
    int seq[max_len];
    for (int i = max_len - 1; i >= 0; i--)
    {
        seq[i] = a[cur];
        cur = par[cur];
    }
    for (int i = 0; i < max_len; i++)
    {
        cout << seq[i] << " ";
    }
    cout << "\n";

    return 0;
}