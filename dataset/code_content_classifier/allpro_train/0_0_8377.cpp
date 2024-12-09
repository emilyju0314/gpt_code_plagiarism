#include <iostream>
#define MOD 998244353

using namespace std;

long long powmod(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    long long total_colorings = powmod(3, n*n);

    long long lucky_colorings = 0;
    long long sign = 1;
    long long curr = 1;
    for (int i = 1; i <= n; i++) {
        curr = (curr * (3 - i + 1)) % MOD;
        lucky_colorings = (lucky_colorings + sign*curr) % MOD;
        sign = -sign;
    }

    long long result = (total_colorings - lucky_colorings + MOD) % MOD;
    cout << result << endl;

    return 0;
}