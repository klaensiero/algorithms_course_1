#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int mass[n][2];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            cin >> mass[i][j];
        }
    }

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {

            if (mass[j][1] < mass[j + 1][1])
                swap(mass[j], mass[j + 1]);

            if (mass[j][1] == mass[j + 1][1])
            {
                if (mass[j][0] > mass[j + 1][0])
                    swap(mass[j], mass[j + 1]);
            }
        }
    }

    for (int i = 0; i < n; ++i)
        cout << mass[i][0] << " " << mass[i][1] << "\n";

    return 0;
}