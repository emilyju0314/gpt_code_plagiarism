#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 505;

int n, m, mod;
char a[MAXN][MAXN];
int dp[MAXN][1 << 9];
int cnt[1 << 9];

inline int add(int x, int y) {
    return (x += y) >= mod ? x - mod : x;
}

int solve(int pos, int mask) {
    if (pos == n) {
        return mask == 0;
    }
    if (dp[pos][mask] != -1) {
        return dp[pos][mask];
    }
    int val = 0;
    for (int i = 0; i < (1 << n); ++i) {
        if ((i & mask) == mask && (i & cnt[pos]) == cnt[pos]) {
            int good = 1;
            for (int j = 0; j < n; ++j) {
                if ((i & (1 << j)) && a[pos][j] == '1') {
                    good = 0;
                    break;
                }
                if (!(i & (1 << j)) && a[pos][j] == '0') {
                    good = 0;
                    break;
                }
            }
            if (good) {
                val = add(val, solve(pos + 1, (i >> 1)));
            }
        }
    }
    return dp[pos][mask] = val;
}

int main() {
    cin >> n >> m >> mod;
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cnt[i] += (a[j][i] == '0');
        }
        cnt[i] = (1 << n) - (1 << cnt[i]);
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(m, 0) << endl;
    return 0;
}