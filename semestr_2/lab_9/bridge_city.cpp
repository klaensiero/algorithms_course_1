#include <bits/stdc++.h>
using namespace std;

const long MN = 10000000;
int head[MN], nxt[MN], to[MN], visited_vertex[MN], idx = 0;

void edge_func(int& u, int& v) {
    nxt[++idx] = head[u];
    head[u] = idx;
    to[idx] = v;
}

bool dfs_func(int u, int par) {
    visited_vertex[u] = 1;
    for (int i = head[u]; i; i = nxt[i]) {
        int v = to[i];
        if (v == par) continue;
        if (visited_vertex[v]) return true;
        if (dfs_func(v, u)) return true;
    }
    return false;
}

void run () {
    bool check_cycle = 0;
    long count = 1;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edge_func(u, v);
        edge_func(v, u);
    }
    bool check = false;
    for (int i = 1; i <= n; i++) {
        if (!visited_vertex[i]) {
            if (dfs_func(i, -1)) {
                check = true;
                break;
            }
        }
    }
    if (check) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}
int main() {   
    run ();
    return 0;
}
