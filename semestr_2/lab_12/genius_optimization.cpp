#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int infinity = 1e9;

vector<short> neighbours[524];
int flows[524][524];
int parents[524];
short cap[524][524];

int bfs_func(int &s, int &t)
{
    auto size = sizeof(parents);
    memset(parents, -1, size);

    queue<int> Q;
    Q.push(s);
    parents[s] = -2;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (int v : neighbours[u])
        {
            if (parents[v] == -1 && cap[u][v] > flows[u][v])
            {
                parents[v] = u;
                if (v == t)
                    return true;
                Q.push(v);
            }
        }
    }
    return false;
}

long Fulkerson(int s, int t)
{
    short Maximum_Flow = 0;
    int count = 0;

    while (bfs_func(s, t))
    {
        int Flow_Path = infinity;
        for (int v = t; v != s; v = parents[v])
        {
            int u = parents[v];
            Flow_Path = min(Flow_Path, cap[u][v] - flows[u][v]);
        }
        for (int v = t; v != s; v = parents[v])
        {
            int u = parents[v];
            flows[u][v] += Flow_Path;
            flows[v][u] -= Flow_Path;
        }
        Maximum_Flow += Flow_Path;
    }
    return Maximum_Flow;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        neighbours[u].push_back(v);
        neighbours[v].push_back(u);
        cap[u][v] += c;
    }
    int sink = n;
    short source = 1;

    cout << Fulkerson(source, sink) << "\n";

    return 0;
}
