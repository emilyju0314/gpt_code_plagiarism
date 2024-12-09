#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define MOD 1000000007

using namespace std;

int n, k;
vector<int> a;

map<pair<int, int>, long long> dp;

long long solve(int idx, int remaining) {
    if (remaining == 0) return 0;

    if (dp.find({idx, remaining}) != dp.end()) return dp[{idx, remaining}];

    long long ans = 0;
    long long sum = 0;

    for (int i = 0; i < k; i++) {
        long long prob = (i == a[idx] || a[idx] == -1) ? 1 : 0;

        if (prob == 0) sum += solve(idx, remaining - 1);

        ans += (prob * (sum % MOD)) % MOD;
        sum = (sum + 1) % MOD;
    }

    ans = (ans * (n - 1)) % MOD;
    ans = (ans * modInverse(k)) % MOD;

    return dp[{idx, remaining}] = (ans + solve((idx + 1) % n, remaining)) % MOD;
}

long long modInverse(long long a) {
    long long m = MOD;
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;

    if (m == 1) return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) x1 += m0;

    return x1;
}

int main() {
    cin >> n >> k;

    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << solve(0, count(a.begin(), a.end(), -1)) << endl;

    return 0;
}