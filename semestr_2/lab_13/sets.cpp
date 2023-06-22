#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    int count;

    set<short> S1, S2;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        S1.insert(x);
    }

    
    for (int i = 0; i < n; i++) {
        int y;
        cin >> y;
        S2.insert(y);
    }

    if (S1.size() != S2.size())
        cout << "NO\n";

    else {
        auto t1 = S1.begin();
        auto t2 = S2.begin();
        bool eq = true;
        while (t1 != S1.end() && t2 != S2.end()) {
            if (*t1 != *t2) {
                eq = 0;
                break;
            }

            t1++;
            t2++;
        }
        if (eq)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
