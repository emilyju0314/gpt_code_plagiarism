#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll dp[2][303][303];

int main()
{
    ll n, m;
    cin >> n >> m;
    dp[0][1][1] = 1;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k < j; k++){
                dp[i % 2][j][k] = (dp[(i + 1) % 2][j][k] * (j - k) + dp[(i + 1) % 2][j - 1][k] * (n - j + 1)) % MOD;
            }
            dp[i % 2][j][j] = dp[(i + 1) % 2][j][j] * j % MOD;
            for(int k = 1; k < j; k++) dp[i % 2][j][j] = (dp[i % 2][j][j] + dp[(i + 1) % 2][j][k] * k) % MOD;
        }
    }
    cout << dp[m % 2][n][n] << endl;
}
