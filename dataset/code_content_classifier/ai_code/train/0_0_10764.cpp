#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int xorSum = 0;
    
    for (int i = 0; i < n; i++) {
        long long x, m;
        cin >> x >> m;
        
        if (m % 2 == 1) {
            xorSum ^= x;
        }
    }
    
    if (xorSum == 0) {
        cout << "bolik" << endl;
    } else {
        cout << "tolik" << endl;
    }
    
    return 0;
}