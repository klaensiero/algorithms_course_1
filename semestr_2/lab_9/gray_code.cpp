#include <iostream>
#include <string>
#include <vector>
using namespace std;
void func(int n) {

}

int main() { 
    int n, i, j;
    cin >> n;

    if (n == 0)
        return;

    vector<string> mes;
    mes.push_back("0");
    mes.push_back("1");

    for (i = 2; i < (1 << n); i = i << 1) {
        for (j = i-1 ; j >= 0 ; j--)
            mes.push_back(mes[j]);
        for (j = 0 ; j < i ; j++)
            mes[j] = "0" + mes[j];
        for (j = i ; j < 2*i ; j++)
            mes[j] = "1" + mes[j];
    }

    for (i = 0 ; i < mes.size() ; i++) 
        cout << mes[i] << "\n";
    return 0; 

}