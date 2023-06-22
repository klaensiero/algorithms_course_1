#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct EDGE {
    int u, v, w;
    EDGE(int u, int v, int w) : u(u), v(v), w(w) {}
};


int find(vector<int>& parents, int i) {
    if (parents[i] == i) return i;
    return parents[i] = find(parents, parents[i]);
}

bool sort_func(const EDGE& a, const EDGE& b) {
    return a.w < b.w;
}

void unite(vector<int>& parents, vector<int>& rank, int &x, int &y) {
    int X = find(parents, x);
    int Y = find(parents, y);

    if (rank[X] > rank[Y])
        parents[Y] = X;
    else if (rank[X] < rank[Y])
        parents[X] = Y;
    else {
        parents[Y] = X;
        rank[X]++;
    }
}

int main() {
    vector<EDGE> edges;
    int n, m;
    long answer = 0;

    cin >> n >> m;
    
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(EDGE(u, v, w));
    }

    sort(edges.begin(), edges.end(), sort_func);
    vector<int> parents(n + 1);
    vector<int> rank(n + 1);
    for (int i = 1; i <= n; i++) {
        parents[i] = i;
        rank[i] = 0;
    }

    int count = 0;
    long long result = 0;
    for (int i = 0; i < m; i++) {
        EDGE edge = edges[i];
        int u = edge.u;
        int v = edge.v;
        int w = edge.w;
        if (find(parents, u) != find(parents, v)) {
            unite(parents, rank, u, v);
            
            result += w;
            count+=1;

            if (count == n - 1)
                break;
        }
    }

    cout << result << "\n";

    return 0;
}
