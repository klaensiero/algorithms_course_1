#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5;
long n, m, q;

vector<short> g[MN], rg[MN], scc[MN], top_sorted;
bool visited_dots[MN];

void dfs_topsort(int u) {
    visited_dots[u] = true;
    for (int v : g[u]) {
        if (!visited_dots[v]) {
            dfs_topsort(v);
        }
    }
    top_sorted.push_back(u);
}

void dfs_comp(int u, int c) {
    visited_dots[u] = true;
    scc[c].push_back(u);
    for (int v : rg[u]) {
        if (!visited_dots[v]) {
            dfs_comp(v, c);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> q;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        rg[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited_dots[i])
            dfs_topsort(i);
        
    }

    memset(visited_dots, false, sizeof(visited_dots));
    int count = 0;
    for (int i = n - 1; i >= 0; i--) {
        int u = top_sorted[i];
        if (!visited_dots[u]) {
            count++;
            dfs_comp(u, count);
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        if (a == b) {
            cout << "YES\n";
            continue;
        }

        int u = -1, v = -1;
        for (int c = 1; c <= count; c++) {
            bool has_vert1 = false, has_vert2 = false;
            for (int x : scc[c]) {
                if (x == a)
                    has_vert1 = true;
                
                if (x == b)
                    has_vert2 = true;
                
            }
            
            if (has_vert1 && has_vert2) {
                u = c;
                break;
            } else if (has_vert1)
                u = c;
             else if (has_vert2) 
                v = c;
            
        }
        if (u == v || u == -1 || v == -1)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    
    return 0;
}
