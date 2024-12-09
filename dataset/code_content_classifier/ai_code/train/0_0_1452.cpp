#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MOD = 1e9 + 7;

int N, A;
int dp[5001][5001], sum[5001];

int add(int a, int b) {
    return (a + b) % MOD;
}

int mul(int a, int b) {
    return (1LL * a*b) % MOD;
}

int main() {
    cin >> N >> A;
    memset(dp, 0, sizeof(dp));
    memset(sum, 0, sizeof(sum));
    
    dp[0][0] = 1;
    sum[0] = 1;
    
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=min(i, A); j++) {
            dp[i][j] = add(sum[i-1], MOD - dp[i-1][j-1]);
            sum[i] = add(sum[i], dp[i][j]);
        }
    }
    
    int ans = 0;
    for(int j=1; j<=A; j++) {
        ans = add(ans, mul(j, dp[N][j]));
    }
    
    cout << ans << endl;
    
    return 0;
}