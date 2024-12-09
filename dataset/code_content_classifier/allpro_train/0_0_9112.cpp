#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

long long power(long long x, long long y) {
    long long res = 1;
    x = x % MOD;

    while (y > 0) {
        if (y & 1)
            res = (res * x) % MOD;
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}

int main() {
    int t;
    cin >> t;

    vector<long long> m(t);

    for (int i = 0; i < t; i++) {
        cin >> m[i];
    }

    for (int i = 0; i < t; i++) {
        // Number of polynomials P such that P(2) = m[i] is (2m[i] choose m[i]) % MOD
        long long n = 2 * m[i];
        long long r = m[i];
        long long num = 1;
        long long den = 1;

        for (int j = 0; j < r; j++) {
            num = (num * (n - j)) % MOD;
            den = (den * (j + 1)) % MOD;
        }

        long long result = (num * power(den, MOD - 2)) % MOD;
        cout << result << endl;
    }

    return 0;
}