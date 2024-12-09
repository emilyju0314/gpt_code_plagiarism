#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int dp[11][11] = {0};
    for(int i = 1; i <= n; i++) {
        dp[1][i] = dp[i][1] = 1;
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 2; j <= n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    cout << dp[n][n] << endl;

    return 0;
}