#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int pow_mod(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (1LL * res * a) % MOD;
        }
        a = (1LL * a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int inv_mod(int a) {
    return pow_mod(a, MOD - 2);
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> fact(N+M+1, 1);
    for (int i = 1; i <= N+M; i++) {
        fact[i] = (1LL * fact[i-1] * i) % MOD;
    }

    int invN = inv_mod(fact[N]);
    int invM = inv_mod(fact[M]);
    int invNM = inv_mod(fact[N+M]);

    int R = ((1LL * fact[N+M-1] * invN) % MOD * invM) % MOD;
    cout << (1LL * R * factor[N+M]) % MOD << endl;

    return 0;
}