#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int infinity = 1e9;

void warshall_func(long **(&neighbours), int n, int K) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (abs(i - k) <= K && abs(j - k) <= K)
                    neighbours[i][j] = min(neighbours[i][j], neighbours[i][k] + neighbours[k][j]);
                
            }
        }
    }
}

int main() {
    int n, m, K, Q;
    cin >> n >> m >> K;

    long** neighbours = new long*[n];
    for (int i = 0; i < n; i++) {
        neighbours[i] = new long[n];
        for (int j = 0; j < n; j++) {

            if (i == j)
                neighbours[i][j] = 0;
            else 
                neighbours[i][j] = infinity;
            
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        neighbours[a][b] = w;
    }

    warshall_func(neighbours, n, K);
    cin >> Q;

    while (Q--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        if (neighbours[a][b] == infinity)
            cout << -1 << "\n";
        else
            cout << neighbours[a][b] << "\n";
    }

    
    return 0;
}
