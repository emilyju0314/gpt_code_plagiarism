#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MOD = 1e9 + 7;

int n, K, M, P;
int dp[105][105][105], f[105][105], C[105][105], pw[105], ans;
vector<int> D;

int mul(int a, int b) {
    return 1ll * a * b % MOD;
}

int binpow(int a, int b, int md) {
    int ret = 1;
    while (b) {
        if (b & 1)
            ret = 1ll * ret * a % md;
        a = 1ll * a * a % md;
        b >>= 1;
    }
    return ret;
}

int Cnk(int n, int k) {
    return 1ll * f[n][k] * binpow(1ll * f[k][k] * f[n - k][k] % P, P - 2, P) % P;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> M >> K >> P;
    if (K == 1) {
        cout << '1';
        return 0;
    }
    
    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            D.push_back(i);

    f[0][0] = 1;
    for (int i = 1; i <= 100; i++) {
        f[i][0] = 1;
        for (int j = 1; j <= 100; j++)
            f[i][j] = (f[i - 1][j - 1] + f[i - 1][j]) % P;
    }

    for (int i = 0; i <= M; i++)
        dp[0][i][i == 0] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= M; j++)
            for (int k = 0; k <= i; k++)
                for (int l = 0; l <= min(j, k); l++)
                    dp[i][j][k] = (dp[i][j][k] + 1ll * dp[i - k][j - l][k == l] * Cnk(i - 1, k - 1) % P * f[k][l]) % P;

    for (int d : D) {
        memset(pw, 0, sizeof pw);
        pw[0] = 1;
        for (int i = 1; i <= K; i++) {
            pw[i] = 0;
            for (int j = 1; j <= i; j++)
                pw[i] = (pw[i] + 1ll * C[K][j] * dp[d][j][i] % P * pw[i - j]) % P;
        }
        ans = (ans + pw[K]) % P;
    }

    cout << ans;

    return 0;
}