#include <iostream>
using namespace std;
#define N 3010
long long dp[N][N];
int main ()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> dp[i][i];
        for (int j = i - 1; j > 0; j --) {
            dp[i][j] = max(dp[i][i] - dp[i - 1][j], dp[j][j] - dp[i][j + 1]);
        }
    }
    cout << dp[n][1];
    return 0;
}