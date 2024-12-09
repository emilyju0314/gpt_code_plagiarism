#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;

        if (m < n-1 || m > n*(n-1)/2) {
            cout << "NO" << endl;
        } else if (n == 1 || k < 3) {
            cout << "YES" << endl;
        } else if (m > n*(n-1)/2 - n) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}