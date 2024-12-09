#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> lis(n, 1); // Initializing LIS lengths with 1
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (a[i] > a[j]) {
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }
        }

        int xor_result = 0;
        for (int length : lis) {
            xor_result ^= length;
        }

        if (xor_result == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}