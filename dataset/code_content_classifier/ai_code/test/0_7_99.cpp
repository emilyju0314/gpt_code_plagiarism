#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long x, n;
        cin >> x >> n;
        
        long long jumps = n * (n + 1) / 2;
        
        if (n % 2 == 1) {
            if (x % 2 == 0) {
                cout << x + jumps << endl;
            } else {
                cout << x - jumps << endl;
            }
        } else {
            if (x % 2 == 0) {
                cout << x - jumps << endl;
            } else {
                cout << x + jumps << endl;
            }
        }
    }

    return 0;
}