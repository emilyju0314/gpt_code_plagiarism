#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        int maxEdges = (n * (n - 1)) / 2;
        
        if (k <= 2 || m > maxEdges || n <= 2) {
            cout << "NO" << endl;
        } else if (m >= n) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}