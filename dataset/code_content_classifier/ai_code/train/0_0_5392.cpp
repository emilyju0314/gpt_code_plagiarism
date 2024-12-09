#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    if (k > n) {
        cout << 0 << endl;
        return 0;
    }

    if (k == 1 || k == n) {
        long long ans = 1;
        for (int i = 0; i < n; i++) {
            ans = (ans * m) % MOD;
        }
        cout << ans << endl;
        return 0;
    }

    if (k % 2 == 0) {
        cout << m << endl;
    } else {
        cout << m*m << endl;
    }

    return 0;
}