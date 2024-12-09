#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
    int N;
    cin >> N;
    
    vector<int> a(2*N-1);
    for(int i=0; i<2*N-1; i++) {
        cin >> a[i];
    }
    
    vector<vector<int>> dp(2*N, vector<int>(N+1, 0));
    dp[0][0] = 1;
    
    for(int i=0; i<2*N-1; i++) {
        for(int j=min(i+1, N); j>=1; j--) {
            dp[i+1][j] = (dp[i+1][j] + dp[i][j-1]) % MOD;
            dp[i+1][j-1] = (dp[i+1][j-1] + dp[i][j]) % MOD;
        }
    }
    
    int answer = (dp[2*N-2][N-1] + dp[2*N-2][N]) % MOD;
    cout << answer << endl;
    
    return 0;
}