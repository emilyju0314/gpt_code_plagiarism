#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MOD = 998244353;

int n, k;
int b[2005];
int dp[2005][2005][105];

int solve(int idx, int cnt, int val) {
    if (cnt > k) return 0;
    if (idx == n) {
        if (val == 0) return 1;
        else return 0;
    }

    int& ret = dp[idx][cnt][val+50];
    if (ret != -1) return ret;

    ret = 0;
    ret = (ret + solve(idx+1, cnt+(val != b[idx]), val)) % MOD;
    ret = (ret + solve(idx+1, cnt+(val+1 != b[idx]), val+1)) % MOD;

    return ret;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    memset(dp, -1, sizeof(dp));
    int ans = (solve(0, 0, 0) + solve(0, 0, 1)) % MOD;
    cout << ans << endl;

    return 0;
}