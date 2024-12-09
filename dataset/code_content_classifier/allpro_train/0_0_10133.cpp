#include <iostream>
using namespace std;

const int M = 1000000007;

int dp[101][11][2];

int main() {
    int n, k, m;
    cin >> n >> k >> m;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j][0] = 1;
            dp[i][j][1] = 1;
        }
    }
    
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            int sum1 = 0, sum2 = 0;
            for (int l = 1; l <= j; l++) {
                sum1 = (sum1 + dp[i - 1][j - l][0]) % M;
            }
            dp[i][j][0] = sum1;
            for (int l = j+1; l <= k; l++) {
                sum2 = (sum2 + dp[i - 1][k - (l-j)][1]) % M;
            }
            dp[i][j][1] = sum2;
        }
    }
    
    int ans = 0;
    for (int j = 1; j <= k; j++) {
        ans = (ans + dp[n][j][0]) % M;
        ans = (ans + dp[n][j][1]) % M;
    }
    
    cout << ans % m << endl;
    
    return 0;
}