#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define MOD 998244353

using namespace std;

int n, k, len;
vector<int> a;
long long dp[100001][101][2];

long long solve(int idx, int lastNum, int consecCount) {
    if (consecCount >= len) {
        return 0;
    }
    if (idx == n) {
        return 1;
    }
    if (dp[idx][lastNum][consecCount] != -1) {
        return dp[idx][lastNum][consecCount];
    }

    long long ways = 0;
    if (a[idx] == -1) {
        for (int i = 1; i <= k; i++) {
            if (i != lastNum) {
                ways = (ways + solve(idx+1, i, consecCount + (i == lastNum))) % MOD;
            }
        }
    } else {
        ways = solve(idx+1, a[idx], consecCount + (a[idx] == lastNum));
    }

    return dp[idx][lastNum][consecCount] = ways;
}

int main() {
    cin >> n >> k >> len;

    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    memset(dp, -1, sizeof(dp));

    long long ans = solve(0, 0, 0);
    cout << ans << endl;

    return 0;
}