#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MOD = 1e9 + 7;

int power(int base, int exp, int mod) {
    int res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) {
            res = (1LL * res * base) % mod;
        }
        base = (1LL * base * base) % mod;
        exp >>= 1;
    }
    return res;
}

int inverse(int x, int mod) {
    return power(x, mod - 2, mod);
}

int main() {
    int p, alpha;
    cin >> p >> alpha;

    string A_str;
    cin >> A_str;

    int A_mod_p = 0;
    for (char c : A_str) {
        A_mod_p = (10LL * A_mod_p + (c - '0')) % (p - 1);
    }

    if (A_mod_p % p == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> fact(p, 1);
    for (int i = 1; i < p; ++i) {
        fact[i] = (1LL * fact[i - 1] * i) % p;
    }

    int result = 1;
    for (int i = 0; i < alpha; ++i) {
        int inv = inverse(fact[p - 1], p);
        for (int j = 0; j < p - 1; ++j) {
            if ((1LL * j * power(p, i, p) % p) * power(p, alpha - i, p) % p == A_mod_p) {
                result = (1LL * result * (j == 0 ? 1 : fact[p - 1]) % MOD) * inv % MOD;
            }
        }
    }

    for (int i = 0; i < alpha; ++i) {
        result = (1LL * result * power(p, p - 1, MOD)) % MOD;
    }

    cout << result << endl;

    return 0;
}