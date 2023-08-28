#include <iostream>
#include <vector>
using namespace std;

const int infinity = 1e9;

void Bellman_Ford(vector<vector<pair<int, int>>> &neighbours, vector<int> &dist_list, int from_vertex, int n)
{
    dist_list[from_vertex] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        bool relax = false;
        for (int u = 1; u <= n; u++)
        {
            for (const auto &edge : neighbours[u])
            {
                int v = edge.first;
                int weight = edge.second;
                if (dist_list[u] != infinity && dist_list[u] + weight < dist_list[v])
                {
                    dist_list[v] = dist_list[u] + weight;
                    relax = true;
                }
            }
        }
        if (!relax)
            break;
    }
}

int main()
{
    int N, M, Q, from_vertex;
    cin >> N >> M >> Q >> from_vertex;

    vector<vector<pair<int, int>>> neighbours(N + 1);
    for (int i = 0; i < M; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        neighbours[u].emplace_back(v, weight);
        neighbours[v].emplace_back(u, weight);
    }

    vector<int> dist_list(N + 1, infinity);

    Bellman_Ford(neighbours, dist_list, from_vertex, N);

    for (int i = 0; i < Q; i++)
    {
        int d;
        cin >> d;
        if (dist_list[d] == infinity)
            cout << -1 << "\n";
        else
            cout << dist_list[d] << "\n";
    }

    return 0;
}
