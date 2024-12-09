#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

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
        for (int i = 0; i < 31; i++) {
            if (k & (1 << i)) {
                ans = (ans + fastPow(n, i)) % MOD;
            }
        }

        cout << ans << endl;
    }

    return 0;
}