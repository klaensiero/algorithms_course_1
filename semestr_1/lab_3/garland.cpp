#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

double func(vector<double> h1, int n) {
	double r = h1[0], l = 0;
	while ((r-l)>0.000001/(n-1)) {
		h1[1] = (l+r)/2;
		bool check = true;
		for (int i = 2; i < n; ++i) {
			h1[i] = 2*h1[i-1]-h1[i-2]+2;
			if (h1[i]<0) {
				check = false;
				break;
			}
		}

		if (check == true)
			r = h1[1];
		else 
			l = h1[1];

	}
	return h1[n-1];
}

int main() {
    int n;
    vector<double> h1;
	cin >> n;
	h1.resize(n);
	cin >> h1[0];
	double res = func(h1, n);
	cout << fixed << setprecision(2) << res;
    
	return 0;
}