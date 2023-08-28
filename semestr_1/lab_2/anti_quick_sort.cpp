#include <iostream>
using namespace std;

void anti_quicks(int n)
{
    int mass[n], op_elem;
    mass[0] = 1;
    mass[1] = 2;
    for (int i = 2; i < n; ++i)
    {
        mass[i] = i + 1;
        op_elem = mass[i / 2];
        mass[i / 2] = mass[i];
        mass[i] = op_elem;
    }

    for (int i = 0; i < n; ++i)
        cout << mass[i] << " ";
}
int main()
{
    int n;
    cin >> n;
    anti_quicks(n);
    
    return 0;
}