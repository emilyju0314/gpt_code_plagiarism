#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int dp[105][105][105];
int f[105][105];
int n, m, k, p;

void add(int &a, int b) {
    a += b;
    if(a >= MOD) a -= MOD;
}

int solve(int i, int cnt, int mask) {
    if(i == n) {
        return cnt == k;
    }
    if(dp[i][cnt][mask] != -1) return dp[i][cnt][mask];
    int &res = dp[i][cnt][mask];
    res = 0;

    int new_mask = 0;
    for(int j = 0; j < m; ++j) {
        if(!(mask & (1 << j))) {
            new_mask |= (1 << j);
            add(res, solve(i + 1, cnt + 1, new_mask));
        } else {
            add(res, solve(i + 1, cnt, mask));
        }
    }

    return res;
}

void precompute() {
    for(int i = 0; i <= n; ++i) {
        f[0][i] = (i == 0);
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            f[i][j] = ((long long)f[i - 1][j - 1] * j + f[i][j - 1]) % p;
        }
    }
}

int main() {
    cin >> n >> m >> k >> p;

    precompute();

    memset(dp, -1, sizeof(dp));

    int res = 0;
    for(int i = 0; i < m; ++i) {
        res = (res + solve(1, 1, 1 << i)) % p;
    }

    cout << (long long)res * f[n - m][n] % p << endl;

    return 0;
}