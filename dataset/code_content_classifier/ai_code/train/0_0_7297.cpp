#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        long long n, a, b;
        cin >> n >> a >> b;
        
        if (a == 1) {
            if ((n - 1) % b == 0 && (n - 1) / b >= 0) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        } else {
            bool found = false;
            long long x = 1;
            while (x <= n) {
                if ((n - x) % b == 0) {
                    found = true;
                    break;
                }
                if (x > n / a) {
                    break;
                }
                x *= a;
            }
            if (found) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}