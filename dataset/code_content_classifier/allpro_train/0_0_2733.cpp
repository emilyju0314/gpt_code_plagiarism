#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int min_tax = n;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            int tax = max(i, n/i);
            min_tax = min(min_tax, tax);
        }
    }
    
    cout << min_tax << endl;
    
    return 0;
}