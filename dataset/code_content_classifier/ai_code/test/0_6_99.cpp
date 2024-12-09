#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long x, n;
        cin >> x >> n;

        long long pos = n % 2 == 0 ? n/2 : -(n/2);
        long long rem = n * (n + 1) / 2;
        
        if (rem % 2 != 0) {
            pos += x % 2 == 0 ? rem : -rem;
        } else {
            pos += x % 2 == 0 ? -rem : rem;
        }
        
        cout << x + pos << endl;
    }

    return 0;
}