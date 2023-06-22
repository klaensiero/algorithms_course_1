#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct EDGES {
    int u, v, w;
};

bool sort_edges(EDGES a, EDGES b) {
    return a.w < b.w;
}

int find(int u, vector<int>& parents) {
    if (parents[u] == u)
        return u;

    return parents[u] = find(parents[u], parents);
}

void merge(int u, int v, vector<int>& parents) {
    u = find(u, parents);
    v = find(v, parents);
    if (u != v)
        parents[v] = u;
}

short MST_func(int n, vector<EDGES>& edges) {
    vector<int> parents(n+1);
    int result = 0;
    for (int i = 1; i <= n; i++) parents[i] = i;
    sort(edges.begin(), edges.end(), sort_edges);
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        if (find(u, parents) != find(v, parents)) {
            merge(u, v, parents);
            result += w;
        }
    }
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<EDGES> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    auto output = MST_func(n, edges);
    cout << output << "\n";

    return 0;
}
