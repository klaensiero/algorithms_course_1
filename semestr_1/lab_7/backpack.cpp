#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int func(int s, int n, int w[])
{
    int dp[n + 1][s + 1];
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= s; ++j)
        {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= s; ++j)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i - 1])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i - 1]] + w[i - 1]);
            }
        }
    }
    return dp[n][s];
}

int main()
{
    int s, n;
    cin >> s >> n;
    int w[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> w[i];
    }
    cout << func(s, n, w) << "\n";
    return 0;
}