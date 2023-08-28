#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void dfs_func(int u, vector<vector<short>> &neighbours, vector<bool> &visited_dots, vector<int> &vertex_order)
{
    visited_dots[u] = true;
    for (int v : neighbours[u])
    {
        if (!visited_dots[v])
            dfs_func(v, neighbours, visited_dots, vertex_order);
    }

    vertex_order.push_back(u);
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> sorted;
    vector<int> new_vertices(n);
    vector<bool> visited_dots(n, false);
    vector<int> vertex_order;
    vector<vector<short>> neighbours(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        neighbours[u - 1].push_back(v - 1);
    }

    for (int u = 0; u < n; u++)
    {
        if (!visited_dots[u])
            dfs_func(u, neighbours, visited_dots, vertex_order);
    }

    reverse(vertex_order.begin(), vertex_order.end());

    for (int i = 0; i < n; i++)
        new_vertices[vertex_order[i]] = i + 1;

    for (int j = 0; j < n; j++)
        cout << new_vertices[j] << "  ";

    return 0;
}
