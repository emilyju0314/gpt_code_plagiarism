#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int power(int x, int y) {
    int res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res = (1LL * res * x) % MOD;
        }
        x = (1LL * x * x) % MOD;
        y /= 2;
    }
    return res;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k, x;
        cin >> n >> k >> x;

        int m = min(20, k);
        int ans = power(2, n - 1);

        if (n == 1) {
            ans = 1;
        } else if (n == 2) {
            ans = 2;
        } else {
            ans = 2 * ans;
        }

        // If x is 0 and k > 0
        if (x == 0 && k > 0) {
            ans = (ans - 2 + MOD) % MOD;
        }

        cout << ans << endl;
    }

    return 0;
}