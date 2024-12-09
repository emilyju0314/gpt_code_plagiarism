#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    
    vector<vector<int>> dp(A+1, vector<int>(B+1, 0));

    dp[0][0] = 1;

    for(int i=0; i<=A; i++) {
        for(int j=0; j<=B; j++) {
            if(i>0) dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            if(j>0) dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
            if(i>0 && j>0) dp[i][j] = (dp[i][j] - dp[i-1][j-1] + MOD) % MOD;
        }
    }

    cout << dp[A][B] << endl;

    return 0;
}