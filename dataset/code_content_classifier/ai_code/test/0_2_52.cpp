#include <iostream>
#include <cmath>
using namespace std;

const long long MOD = 1e9 + 7;

long long fastPow(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        long long ans = 0;
        int bitPos = 0;

        for (int i = 0; i < 31 && ans < k; i++) {
            if ((k >> i) & 1) {
                ans += fastPow(n, i);
                ans %= MOD;
            }
            bitPos = i;
        }

        if (ans < k) {
            ans += fastPow(n, bitPos + 1) * ((k - ans + fastPow(n, bitPos + 1) - 1) / fastPow(n, bitPos + 1));
            ans %= MOD;
        }

        cout << ans << endl;
    }

    return 0;
}