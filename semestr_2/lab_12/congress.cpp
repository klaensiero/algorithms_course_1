#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

short parents[10000];

int find(int x) {
    if (parents[x] != x)
        parents[x] = find(parents[x]);
    return parents[x];
}

void merge(int x, int y) {
    parents[find(x)] = find(y);
}

int kruskal_func(int skip_edges, int &n, vector<pair<int, pair<int, int>>>& EDGES) {
    long result = 0;

    for (int i = 0; i <= n; i++)
        parents[i] = i;

    for (int i = 0; i < EDGES.size(); i++) {

        if (i == skip_edges)
            continue;

        int u = EDGES[i].second.first, v = EDGES[i].second.second, w = EDGES[i].first;

        if (find(u) != find(v)) {
            merge(u, v);
            result += w;
        }
    }

    return result;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> EDGES(m);
    
    for (int i = 1; i < m; i++)
        cin >> EDGES[i].second.first >> EDGES[i].second.second >> EDGES[i].first;

    sort(EDGES.begin(), EDGES.end());

    int S1 = kruskal_func(-1, n, EDGES);
    long S2 = 1e9;

    for (int i = 0; i < m; i++) {
        int S = kruskal_func(i, n, EDGES);

        if (S != S1 && S < S2)
            S2 = S;

    }

    cout << S1 << " " << S2 << "\n";

    return 0;
}
