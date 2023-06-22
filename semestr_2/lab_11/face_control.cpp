#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct EDGE {
    int u, v, weight;
};

bool Ford_Bellman(int n, int m, const vector<EDGE>& edges, int k) {
    vector<int> dist_list(n + 1, INT_MAX);
    dist_list[1] = 0;
    bool visited;
    for (int i = 0; i < n - 1; i++) {
        visited = false;
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int weight = edges[j].weight;
            if (dist_list[u] < INT_MAX && dist_list[v] > dist_list[u] + weight) {
                dist_list[v] = dist_list[u] + weight;
                visited = true;
            }
        }
        if (!visited)
            break;
    }
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int weight = edges[j].weight;
        if (dist_list[u] < INT_MAX && dist_list[v] > dist_list[u] + weight) {
            if (dist_list[u] + weight - dist_list[v] <= k) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int Q, k;
    cin >> Q >> k;

    for (int i = 0; i < Q; i++) {
        int n, m;
        cin >> n >> m;
        vector<EDGE> edges(m);
        for (int j = 0; j < m; j++) {
            cin >> edges[j].u >> edges[j].v >> edges[j].weight;
        }

        bool check = Ford_Bellman(n, m, edges, k);
        if (check)
            cout << "NO" << "\n";
        else 
            cout << "YES" << "\n";
        
    }

    return 0;
}
