#include <iostream>
#include <string>
#include <vector>
using namespace std;
void func(int n) {
    if (n == 0)
        return;
    vector<string> mes;
    mes.push_back("0");
    mes.push_back("1");
    int i, j;
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
}
int main() { 
    int n;
    cin >> n;
    func(n); 
    return 0; 
}