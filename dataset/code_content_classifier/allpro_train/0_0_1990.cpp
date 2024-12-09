#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, C;
    cin >> N >> C;
    
    vector<vector<int>> dp(N+1, vector<int>(C+1, 0));
    
    for(int i = 1; i <= N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        
        for(int j = 0; j <= C; j++) {
            if(j >= c) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-c] + a);
                if(j >= 2*c) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-2*c] + a + b);
                }
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    cout << dp[N][C] << endl;
    
    return 0;
}