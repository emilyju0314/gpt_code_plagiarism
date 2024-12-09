#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 998244353

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<long long, long long>> robots;
    for(int i = 0; i < N; i++) {
        long long x, d;
        cin >> x >> d;
        robots.push_back(make_pair(x, d));
    }

    sort(robots.begin(), robots.end());

    long long ans = 1;
    vector<long long> dp(N, 1);

    for(int i = 0; i < N; i++) {
        long long x = robots[i].first;
        long long d = robots[i].second;

        int idx = lower_bound(robots.begin(), robots.end(), make_pair(x + d, 0LL)) - robots.begin();
        dp[i] = (idx == N) ? 1 : (2 * dp[i] + MOD - dp[idx]) % MOD;
        ans = (ans + dp[i]) % MOD;
    }

    cout << ans << endl;

    return 0;
}