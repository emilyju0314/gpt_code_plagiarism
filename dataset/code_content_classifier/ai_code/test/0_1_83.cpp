#include <iostream>
#include <cmath>

using namespace std;

const long long M = 998244353;
const long long MOD = 1e9 + 7;

long long mod_pow(long long base, long long exp) {
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
    long long n;
    cin >> n;

    long long ans = 0;
    long long k = 1;

    while (k <= n) {
        long long next_k = 10 * k;
        if (next_k > n) {
            next_k = n + 1;
        }

        long long s = (n / k) % MOD;
        long long r = (n % k) % MOD;
        
        long long temp1 = (((k % MOD) * s) % MOD);
        long long temp2 = (((s * (s - 1)) / 2) % MOD) * k % MOD;
        long long temp3 = (r + 1) % MOD;

        long long total = (((((((temp1 - temp2) % MOD) + MOD) % MOD) * temp3) % MOD) + M - (r + MOD) % MOD) % MOD;
        
        ans = (ans + total) % MOD;
        k = next_k;
    }

    cout << ans << endl;

    return 0;
}