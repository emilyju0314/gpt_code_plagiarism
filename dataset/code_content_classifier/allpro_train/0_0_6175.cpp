#include <iostream>
#include <cstring>
#define MAXN 155

using namespace std;

const int MOD = 1e9 + 7;
int n, m;
int dp[MAXN][MAXN][MAXN * MAXN];

int add(int a, int b) {
    return (a + b) % MOD;
}

int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

int solve(int r, int c, int cnt) {
    if(cnt < 0) return 0;
    if(r == 0) return cnt == 0;
    if(dp[r][c][cnt] != -1) return dp[r][c][cnt];

    int ans = solve(r-1, c, cnt);
    ans = add(ans, solve(r, c-1, cnt));
    if(r == 1 || c == 1)
        ans = add(ans, solve(r, c, cnt-1));
    else {
        ans = add(ans, mul(cnt, r-1));
        ans = add(ans, mul(cnt, c-1));
        ans = add(ans, MOD - mul(cnt, cnt-1));
        ans = add(ans, solve(r-2, c, cnt-1));
        ans = add(ans, solve(r, c-2, cnt-1));
    }

    return dp[r][c][cnt] = ans;
}

int main() {
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    cout << solve(n, m, n * m) << endl;

    return 0;
}