#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long limit = 1e9;

int main() {
    int n, m;
    long count;
    
    cin >> n >> m;
    vector<vector<int>> neighbours(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        neighbours[u].push_back(v);
        neighbours[v].push_back(u);
    }
    int s, dest;
    cin >> s >> dest;
    vector<int> graph(n + 1, limit);
    queue<int> q;

    graph[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : neighbours[u]) {
            if (graph[v] == limit) {
                graph[v] = graph[u] + 1;
                q.push(v);
            }
        }
    }

    if (graph[dest] == limit)
        cout << "-1\n";
    else 
        cout << graph[dest] << "\n";

    return 0;
}
