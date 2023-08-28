#include <iostream>
#include <vector>
using namespace std;

int chairs_func(vector<int> &chairs)
{
    int c = 0;
    int n = chairs.size();
    vector<int> frequencies(2 * n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        int diff = chairs[i] - i + n;
        c += frequencies[diff];
        frequencies[diff] += 1;
    }

    return c;
}

int main()
{
    int n;
    cin >> n;

    vector<int> chairs(n);
    for (int i = 0; i < n; i++)
        cin >> chairs[i];

    cout << chairs_func(chairs) << "\n";

    return 0;
}
