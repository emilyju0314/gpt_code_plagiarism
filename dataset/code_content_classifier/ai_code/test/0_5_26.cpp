#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1e9 + 7;

long long fastPower(long long base, long long power) {
    long long result = 1;
    while (power > 0) {
        if (power % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        power /= 2;
    }
    return result;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> fact(2*n + 1, 1);
        for (int i = 1; i <= 2*n; i++) {
            fact[i] = (fact[i-1] * i) % MOD;
        }

        long long ans = fact[2*n];
        long long inv_n_factorial = fastPower(fact[n], MOD - 2);
        long long inv_n_plus_1_factorial = fastPower(fact[n+1], MOD - 2);

        ans = (ans * inv_n_factorial) % MOD;
        ans = (ans * inv_n_plus_1_factorial) % MOD;

        cout << ans << endl;
    }

    return 0;
}