#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int hash_func(int GROUP) {
    return GROUP % 100000;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int M, Q;
    cin >> M >> Q;

    vector<vector<pair<int, int>>> GROUPS(100000);

    while (Q--) {
        char op;
        int GROUP, ISU, POINTS;

        cin >> op;
        if (op == '+') {
            cin >> GROUP >> ISU >> POINTS;
            int ind = hash_func(GROUP);
            GROUPS[ind].emplace_back(ISU, POINTS);
        } else if (op == '-') {
            cin >> GROUP >> ISU;
            int ind = hash_func(GROUP);
            auto& group_data = GROUPS[ind];
            group_data.erase(remove_if(group_data.begin(), group_data.end(), [&](const pair<int, int>& p) {
                return p.first == ISU;
            }), group_data.end());

        } else if (op == 'm') {
            cin >> GROUP;
            int ind = hash_func(GROUP);
            int Max_points = 0;
            for (const auto& s : GROUPS[ind])
                Max_points = max(Max_points, s.second);
            
            cout << Max_points << "\n";
        } else if (op == 'a') {
            cin >> GROUP;

            int ind = hash_func(GROUP);
            int total = 0;
            int studentCount = GROUPS[ind].size();

            for (const auto& s : GROUPS[ind])
                total += s.second;
            
            cout << (studentCount > 0 ? total / studentCount : 0) << "\n";
        }
    }

    return 0;
}
