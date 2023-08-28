#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &mass, int left, int pivot_elem)
{

    int i = left;

    while (i < pivot_elem)
    {
        if (mass[i] > mass[pivot_elem] && i == pivot_elem - 1)
        {
            swap(mass[i], mass[pivot_elem]);
            pivot_elem -= 1;
        }

        if (mass[i] > mass[pivot_elem])
        {
            swap(mass[pivot_elem - 1], mass[pivot_elem]);
            swap(mass[i], mass[pivot_elem]);
            pivot_elem -= 1;
        }

        else
            i++;
    }
    return pivot_elem;
}

void quicks(vector<int> &mass, int left, int right)
{
    if (left < right)
    {
        int pivot_elem = partition(mass, left, right);
        quicks(mass, left, pivot_elem - 1);
        quicks(mass, pivot_elem + 1, right);
    }
}

int main()
{
    vector<int> mass1;
    vector<int> mass2;
    int k1, k2, elem;
    cin >> k1;

    for (int i = 0; i < k1; ++i)
    {
        cin >> elem;
        mass1.push_back(elem);
    }

    cin >> k2;
    for (int i = 0; i < k2; ++i)
    {
        cin >> elem;
        mass2.push_back(elem);
    }

    sort(mass1.begin(), mass1.end());
    sort(mass2.begin(), mass2.end());

    for (int i = 0; i < mass1.size() - 1; ++i)
    {

        if (mass1[i] == mass1[i + 1])
        {
            mass1.erase(mass1.begin() + i + 1);
            i -= 1;
        }
    }

    for (int i = 0; i < mass2.size() - 1; ++i)
    {
        if (mass2[i] == mass2[i + 1])
        {
            mass2.erase(mass2.begin() + i + 1);
            i -= 1;
        }
    }

    if (mass1.size() == mass2.size())
    {
        for (int i = 0; i < mass1.size(); ++i)
        {
            if (mass1[i] != mass2[i])
            {
                cout << "NO";
                return 0;
            }
        }
        cout << "YES";
    }

    if (mass1.size() != mass2.size())
        cout << "NO";

    return 0;
}