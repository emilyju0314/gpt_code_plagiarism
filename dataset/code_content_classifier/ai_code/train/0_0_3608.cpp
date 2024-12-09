#include <iostream>
#include <vector>

using namespace std;

int n, p, l, r;

long long power(long long x, long long y, long long p) {
    long long res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int main() {
    cin >> n >> p >> l >> r;

    vector<long long> fact(n + 1);
    fact[0] = 1;

    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % p;
    }

    long long ans = 0;
    for (int k = l; k <= r; k++) {
        if (n - k >= 0 && k >= 0) {
            ans = (ans + (fact[n] * power(fact[k] * fact[n - k], p - 2, p)) % p) % p;
        }
    }

    cout << ans << endl;
    
    return 0;
}