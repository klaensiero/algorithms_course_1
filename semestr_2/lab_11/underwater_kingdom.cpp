#include <iostream>
#include <vector>
using namespace std;

const int infinity = 1e9;

struct EDGES
{
    int to_vertex;
    int weight;
};

vector<vector<EDGES>> G;
vector<int> dist_list;

void dfs_func(int u)
{
    for (const auto &edge : G[u])
    {
        int v = edge.to_vertex;
        int w = edge.weight;

        if (dist_list[u] + w < dist_list[v])
        {
            dist_list[v] = dist_list[u] + w;
            dfs_func(v);
        }
    }
}

int main()
{
    int N, M, S, T;
    cin >> N >> M;
    cin >> S >> T;

    G.resize(N + 1);
    dist_list.assign(N + 1, infinity);
    dist_list[S] = 0;

    for (int i = 0; i < M; i++)
    {
        int A, B, W;
        cin >> A >> B >> W;
        G[A].push_back({B, W});
    }

    dfs_func(S);

    if (dist_list[T] == infinity)
        cout << -1 << "\n";
    else
        cout << dist_list[T] << "\n";

    cout << "\n";

    return 0;
}
