#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> a(K);
    for(int i=0; i<K; i++){
        cin >> a[i];
    }
    
    vector<vector<long long>> dp(K+1, vector<long long>(N+1, 0));
    dp[0][1] = 1;
    
    for(int i=1; i<=K; i++){
        for(int j=1; j<=N; j++){
            dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            for(int k=2; k<=N; k++){
                dp[i][k] = (dp[i][k] + dp[i-1][j]) % MOD;
            }
        }
    }
    
    long long ans = 0;
    for(int i=1; i<=N; i++){
        ans = (ans + dp[K][i]) % MOD;
    }
    
    cout << ans << endl;
    
    return 0;
}