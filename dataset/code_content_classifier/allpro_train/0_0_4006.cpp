#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    int n, m;
    long long p;
    cin >> n >> m >> p;

    vector<int> a(m), b(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        char side;
        cin >> side;
        if (side == 'L') {
            b[i] = 0;
        } else {
            b[i] = 1;
        }
    }

    long long ans = 0;
    for (int i = 0; i < m; i++) {
        long long total_dist = 0;
        for (int j = 0; j < m; j++) {
            total_dist += (abs(a[i] - a[j]) % p);
            total_dist %= p;
        }
        long long exponent = power(2, (m - 1), p);
        if (b[i] == 0) {
            ans += (total_dist * exponent) % p;
        } else {
            ans += ((n - a[i]) * total_dist % p) * exponent % p;
        }
        ans %= p;
    }

    cout << ans << endl;

    return 0;
}