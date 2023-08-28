#include <iostream>
using namespace std;
int main()
{

    int mass[2000];
    int n, pos, num;
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> mass[i];

    cin >> num >> pos;

    for (int i = n; i >= pos; --i)
        mass[i] = mass[i - 1];

    n = n + 1;
    mass[pos - 1] = num;

    for (int i = 0; i < n; ++i)
        cout << mass[i] << " ";

    cout << "\n";

    return 0;
}