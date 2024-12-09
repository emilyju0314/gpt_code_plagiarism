#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

int main() {
    int M;
    cin >> M;
    
    vector<int> X(M);
    vector<int> Y(M);
    for(int i = 0; i < M; i++) {
        cin >> X[i];
    }
    for(int i = 0; i < M; i++) {
        cin >> Y[i];
    }
    
    vector<vector<vector<int>>> dp(101, vector<vector<int>>(101, vector<int>(101, 0)));
    dp[0][0][0] = 1;
    
    for(int i = 1; i <= M; i++) {
        for(int j = 0; j <= i; j++) {
            for(int k = 0; k < M; k++) {
                for(int l = X[k]; l <= Y[k]; l++) {
                    dp[i][j + l][k] = (dp[i][j + l][k] + dp[i-1][j][k]) % MOD;
                }
            }
        }
    }
    
    int ans = 0;
    for(int j = X[M-1]; j <= Y[M-1]; j++) {
        for(int k = 0; k < M; k++) {
            ans = (ans + dp[M][j][k]) % MOD;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}