#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MOD = 998244353;
const int MAXN = 2001;
int n, k;
int b[MAXN];
int dp[MAXN][MAXN][2]; // dp[i][j][0]: number of arrays ending at i with MEX equal to j; dp[i][j][1]: number of arrays with MEX less than j

void add(int &a, int b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

int solve() {
    memset(dp, 0, sizeof(dp));
    dp[0][n][0] = 1;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 2*n; j++) {
            if (dp[i-1][j][0] == 0 && dp[i-1][j][1] == 0) {
                continue;
            }
            for (int x = 0; x <= n; x++) {
                if (abs(j - b[i]) > k) {
                    add(dp[i][x][1], dp[i-1][j][1]);
                    if (x+1 <= n) {
                        add(dp[i][x+1][0], dp[i-1][j][1]);
                    }
                    add(dp[i][x][1], dp[i-1][j][0]);
                } else {
                    add(dp[i][max(x, j)][j == b[i]], dp[i-1][j][0] + dp[i-1][j][1]);
                }
            }
        }
    }
    
    int ans = 0;
    for (int j = 0; j <= n; j++) {
        add(ans, dp[n][j][0]);
        add(ans, dp[n][j][1]);
    }
    
    return ans;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        b[i] += k;
    }

    cout << solve() << endl;

    return 0;
}