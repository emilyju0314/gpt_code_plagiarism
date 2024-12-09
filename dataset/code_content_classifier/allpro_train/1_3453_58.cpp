#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    for(ll n, m, k; cin >> n >> m >> k, n;){
        ll dp[n+1][n*m+1];
        for(ll i = 0; i <= n; i++){
            for(ll j = 0; j <= n * m; j++)dp[i][j] = 0;
        }
        dp[0][0] = 1;
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < n * m; j++){
                if(dp[i][j] == 0)continue;
                for(ll k = 1; k <= m; k++){
                    dp[i+1][j+k] += dp[i][j];
                }
            }
        }
        double a = 0, b = 0;
        for(ll i = 0; i <= n * m; i++){
            a += max(1LL, i - k) * dp[n][i];
            b += dp[n][i];
        }
        printf("%.9f\n", a / b);
    }
    return 0;
}

