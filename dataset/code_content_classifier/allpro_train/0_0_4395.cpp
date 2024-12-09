#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define MOD 998244353

using namespace std;

long long pow_mod(long long a, long long b) {
    long long ans = 1;
    a %= MOD;
    while (b > 0) {
        if (b % 2 == 1)
            ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return ans;
}

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> points(N);

    for (int i = 0; i < N; i++) {
        cin >> points[i].first >> points[i].second;
    }

    sort(points.begin(), points.end());

    long long ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            ans += (pow_mod(2, j) - 1) * (pow_mod(2, N - j - 1) - 1) % MOD * points[j].second % MOD;
            ans %= MOD;
        }
    }

    cout << ans << endl;

    return 0;
}