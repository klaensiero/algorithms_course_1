#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs_func(vector<vector<int>> &neighbours, vector<bool> &visited_dots, int u, int v, bool &found)
{
    visited_dots[u] = true;
    if (u == v)
    {
        found = true;
        return;
    }

    for (int neighbour : neighbours[u])
    {
        if (!visited_dots[neighbour])
            dfs_func(neighbours, visited_dots, neighbour, v, found);
    }
}

int main()
{
    int n, m, q;
    int count_strong_components = 0;
    cin >> n >> m >> q;

    vector<vector<int>> neighbours(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        neighbours[a].push_back(b);
        neighbours[b].push_back(a);
    }

    while (q--)
    {
        char op;
        int a, b;
        cin >> op >> a >> b;
        if (op == '?')
        {
            vector<bool> visited_dots(n + 1, false);
            bool found = false;
            dfs_func(neighbours, visited_dots, a, b, found);
            if (found)
                cout << "YES\n";

            else
                cout << "NO\n";
        }
        else
        {
            auto it = find(neighbours[a].begin(), neighbours[a].end(), b);
            if (it != neighbours[a].end())
                neighbours[a].erase(it);

            it = find(neighbours[b].begin(), neighbours[b].end(), a);
            if (it != neighbours[b].end())
                neighbours[b].erase(it);
        }
    }

    return 0;
}
