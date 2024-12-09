#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int MOD = 1000000007;

int mod_pow(int x, int n, int m) {
    if (n == 0) return 1 % m;
    long long u = mod_pow(x, n / 2, m);
    u = (u * u) % m;
    if (n % 2 == 1) u = (u * x) % m;
    return u;
}

int mod_inverse(int a, int m) {
    return mod_pow(a, m - 2, m);
}

int main() {
    int N, A, B, C;
    cin >> N >> A >> B >> C;

    int winA = (A * mod_inverse(100, MOD)) % MOD;
    int winB = (B * mod_inverse(100, MOD)) % MOD;
    int draw = (C * mod_inverse(100, MOD)) % MOD;

    int den = (1 - winA - winB - draw + MOD) % MOD;
    int num = ((mod_pow(den, N, MOD) - 1 + MOD) % MOD) * mod_inverse((1 - den + MOD) % MOD, MOD) % MOD;

    cout << num << endl;

    return 0;
}