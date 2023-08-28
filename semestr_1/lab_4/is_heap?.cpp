#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int k1, elem;
    int check = 0;
    cin >> k1;
    int arr[100001];
    for (int i = 1; i <= k1; ++i)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= k1 / 2; ++i)
    {
        if ((2 * i <= k1) and (arr[i] > arr[2 * i]))
        {
            check = 1;
            break;
        }
        if ((2 * i + 1 <= k1) and (arr[i] > arr[2 * i + 1]))
        {
            check = 1;
            break;
        }
    }

    if (check == 1)
        cout << "NO";
    else
        cout << "YES";

    return 0;
}