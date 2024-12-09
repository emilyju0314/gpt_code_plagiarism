#include <iostream>
#include <iomanip>
#include <vector>

#define MOD 1000000007

using namespace std;

int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

int expectedTime(int n, int m, int rb, int cb, int rd, int cd, int p) {
    int rowDist = abs(rb - rd);
    int colDist = abs(cb - cd);

    int gcd = __gcd(rowDist, colDist);

    if (gcd == 1) {
        return 2;
    } else {
        long long probability = (long long) p * modInverse(100, MOD) % MOD;
        long long numerator = (2 * MOD - 1 + probability) % MOD;
        long long denominator = modInverse(probability, MOD);
        long long result = (numerator * denominator) % MOD;

        return (int) result;
    }
}

int main() {
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        int n, m, rb, cb, rd, cd, p;
        cin >> n >> m >> rb >> cb >> rd >> cd >> p;

        int result = expectedTime(n, m, rb, cb, rd, cd, p);
        cout << result << endl;
    }

    return 0;
}