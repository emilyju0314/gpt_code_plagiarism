#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string S;
    int K;
    cin >> S >> K;

    int n = S.length();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(S[i] == S[n-1-j]){
                dp[i+1][j+1] = dp[i][j] + 1;
            } else {
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }

    int res = 0;
    for(int i = 0; i <= K; i++){
        for(int j = 0; j <= K; j++){
            if(i + j > K) continue;
            res = max(res, dp[i][n-j] + dp[j][n-i]);
        }
    }

    cout << res << endl;

    return 0;
}