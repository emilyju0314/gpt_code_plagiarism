#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    long long x = n;
    long long powTen = 1;
    
    while (x % 10 != 0 && (x % 10 != k)) {
        x *= n;
        powTen *= 10;
    }
    
    cout << x * powTen << endl;
    
    return 0;
}