#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 205;
const int MAXM = 1000000007;

int n, m;
long long dp[MAXN][MAXN][MAXN];

int main() {
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        dp[i][i][1] = 1;
    }

    for(int len = 2; len <= n; len++) {
        for(int i = 1; i <= n; i++) {
            for(int j = i; j <= n; j++) {
                for(int k = 1; k <= len; k++) {
                    dp[i][j][len] = (dp[i][j][len] + dp[i][j][len - k]) % MAXM;
                    
                    long long cnt = 1;
                    for(int p = i; p <= j; p++) {
                        cnt = cnt * (len - k + 1) % MAXM;
                    }
                    dp[i][j][len] = (dp[i][j][len] + dp[i][j][k - 1] * cnt) % MAXM;
                }
            }
        }
    }

    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            ans = (ans + dp[i][j][n]) % MAXM;
        }
    }

    cout << ans << endl;

    return 0;
}