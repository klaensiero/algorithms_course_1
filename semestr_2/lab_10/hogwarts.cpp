#include <bits/stdc++.h>
using namespace std;

const int MN = 1e6;

int n, m, cc;
bool traps[MN];
vector<int> graph[MN];
int comp[MN];

void dfs_func(int u) {
    comp[u] = cc;
    for (int v : graph[u]) {
        if (comp[v] == 0)
            dfs_func(v);
        
    }
}

int main() {
    int count_components = 1;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        traps[i] = (c == '1');
    }

    for (int i = 1; i <= n; i++) {
        if (comp[i] == 0) {
            cc++;
            dfs_func(i);
        }
    }

    int cnt_components = cc;
    vector<bool> component_traps(cnt_components + 1, false);
    for (int i = 1; i <= n; i++) {
        if (traps[i])
            component_traps[comp[i]] = true;
        
    }

    int cnt_traps = count(component_traps.begin() + 1, component_traps.end(), true);
    cout << cnt_components << "\n";

    for (int i = 1; i <= n; i++)
        cout << comp[i] << " ";
    
    cout << "\n";

    for (int i = 1; i <= cnt_components; i++)
        cout << component_traps[i] << " ";
    
    cout << "\n";


    return 0;
}
