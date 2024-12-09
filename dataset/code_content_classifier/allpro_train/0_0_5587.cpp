#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

long long mod_pow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res % MOD;
}

long long binomial_coefficient(long long n, long long k, long long mod) {
    if (k < 0 || k > n) return 0;
    
    long long numerator = 1;
    long long denominator = 1;
    for (int i = 0; i < k; i++) {
        numerator = (numerator * (n - i)) % mod;
        denominator = (denominator * (i + 1)) % mod;
    }
    return (numerator * mod_pow(denominator, mod - 2)) % mod;
}

int main() {
    int n, k;
    long long l;
    cin >> n >> l >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long ans = 0;
    for (int i = 1; i <= l; i++) {
        ans = (ans + binomial_coefficient(l - (i - 1), i, MOD)) % MOD;
    }

    cout << ans << endl;

    return 0;
}