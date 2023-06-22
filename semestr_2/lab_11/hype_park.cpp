#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int infinity = 1e9;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> neighbours(N, vector<int>(N, infinity));

    for (int i = 0; i < N; i++)
        neighbours[i][i] = 0;
    


    for (int i = 0; i < M; i++) {
        int s, e, l;
        cin >> s >> e >> l;

        s--;
        e--;
        neighbours[s][e] = l;
        neighbours[e][s] = l;
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                neighbours[i][j] = min(neighbours[i][j], neighbours[i][k] + neighbours[k][j]);
            
        }
    }

    int max_dist = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (neighbours[i][j] != infinity)
                max_dist = max(max_dist, neighbours[i][j]);
            
        }
    }

    if (max_dist == 0)
        cout << "0" << "\n";
    else
        cout << max_dist << "\n";

    return 0;
}
