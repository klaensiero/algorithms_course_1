#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool hamiltonian_path_helper(vector<vector<int>>& G, vector<bool>& visited_dots, vector<int>& path_cycle, int cur, int count) {
    int n = G.size();
    if (count == n) {
        return true;
    }
    
    for (int neighbor : G[cur]) {
        if (!visited_dots[neighbor]) {
            path_cycle.push_back(neighbor);
            visited_dots[neighbor] = true;
            if (hamiltonian_path_helper(G, visited_dots, path_cycle, neighbor, count+1)) {
                return true;
            }

            path_cycle.pop_back();
            visited_dots[neighbor] = false;
        }
    }

    return false;
}

string hamiltonian_path(vector<vector<int>>& G) {
    int n = G.size();
    vector<bool> visited_dots(n, false);
    vector<int> path_cycle = {0};
    visited_dots[0] = true;
    if (hamiltonian_path_helper(G, visited_dots, path_cycle, 0, 1)) {
        return "YES";
    }
    
    queue<int> q;
    q.push(0);
    vector<int> dist(n, -1);
    dist[0] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int neighbor : G[cur]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[cur] + 1;
                q.push(neighbor);
            }
        }
    }

    int furthest = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] > dist[furthest]) {
            furthest = i;
        }
    }

    path_cycle = {furthest};
    visited_dots = vector<bool>(n, false);
    visited_dots[furthest] = true;
    if (hamiltonian_path_helper(G, visited_dots, path_cycle, furthest, 1)) {
        return "YES";
    }

    return "NO";
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u-1].push_back(v-1);
        G[v-1].push_back(u-1);
    }

    string res = hamiltonian_path(G);
    cout << res << "\n";
    return 0;
}
