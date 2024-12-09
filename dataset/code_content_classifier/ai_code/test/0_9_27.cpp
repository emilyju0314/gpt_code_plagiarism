#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;

        if(n == 1 || m < n-1 || m > n*(n-1)/2) {
            cout << "NO" << endl;
        } else if(k <= 1 || n == 2) {
            cout << "YES" << endl;
        } else {
            cout << (m <= 2*(n-2) ? "YES" : "NO") << endl;
        }
    }

    return 0;
}