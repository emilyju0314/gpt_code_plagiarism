#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define MOD 998244353

using namespace std;

int n, m;
vector<pair<int, int>> vectors;
map<pair<int, int>, int> hash;

int inv(int a, int m) {
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

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        vectors.push_back({x, y});
    }

    for (int i = 0; i < n; i++) {
        hash[{vectors[i].first, vectors[i].second}] = i;
    }

    int ans = 0;

    for (int i = 0; i < (1 << n); i++) {
        vector<int> combo;
        int x0 = 0, y0 = 0;
        int sign = 1;

        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                combo.push_back(j);
                sign = -sign;
            }
        }

        if (sign == -1) {
            continue;
        }

        int lcmx = 1, lcmy = 1;

        for (auto idx : combo) {
            int x = vectors[idx].first;
            int y = vectors[idx].second;

            int gcd = __gcd(abs(x), abs(y));
            lcmx = (1LL * lcmx * abs(x)) / gcd;
            lcmy = (1LL * lcmy * abs(y)) / gcd;
        }

        int im = inv(lcmx % MOD, MOD);
        int jm = inv(lcmy % MOD, MOD);
        int lcm = 1LL * lcmx * lcmy % MOD;

        int valid = 0;

        for (auto idx : combo) {
            int x = vectors[idx].first;
            int y = vectors[idx].second;

            int u = 1LL * x * im % MOD;
            int v = 1LL * y * jm % MOD;
            int g = hash[{u, v}];

            if (g == idx) {
                valid++;
            }
        }

        if (valid == combo.size()) {
            ans = (ans + 1) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}