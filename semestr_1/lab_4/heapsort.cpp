#include <bits/stdc++.h>
using namespace std;

void heap_build(vector<int> &mass, int len, int root)
{
	int max = root;
	int l = 2 * root + 1;
	int r = 2 * root + 2;
	if (l < len && mass[l] > mass[max])
		max = l;
	if (r < len && mass[r] > mass[max])
		max = r;

	if (max != root)
	{
		swap(mass[root], mass[max]);
		heap_build(mass, len, max);
	}
}

void heapsort(vector<int> &mass, int len)
{
	for (int i = (len / 2) - 1; i >= 0; --i)
		heap_build(mass, len, i);
	for (int i = len - 1; i >= 0; --i)
	{
		swap(mass[0], mass[i]);
		heap_build(mass, i, 0);
	}
}

int main()
{
	vector<int> arr;
	int k1, elem;
	cin >> k1;
	for (int i = 0; i < k1; ++i)
	{
		cin >> elem;
		arr.push_back(elem);
	}
	heapsort(arr, k1);

	for (int i = 0; i < k1; ++i)
		cout << arr[i] << " ";

	return 0;
}