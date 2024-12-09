#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, l, r;
        cin >> n >> l >> r;

        long long ans = 0;

        if (l == 0 && r == 0) {
            if (n == 2) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
            continue;
        }

        if (l == 0) {
            ans = ((r - l + 1) * (r - l)) / 2;
            cout << ans % MOD << endl;
            continue;
        }

        if (r == 0) {
            if (n == 2) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
            continue;
        }

        long long diff = r - l;
        for (int i = 1; i <= n; i++) {
            int low = max(i - r - 1, l - i);
            int high = min(i - l - 1, r - i);
            long long cnt = max(0, high - low + 1);
            ans = (ans + cnt * (n - i + 1)) % MOD;
        }

        cout << ans % MOD << endl;
    }

    return 0;
}