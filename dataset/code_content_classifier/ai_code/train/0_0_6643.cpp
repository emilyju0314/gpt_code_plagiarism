#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
    int X, Y;
    cin >> X >> Y;

    vector<vector<int>> dp(X+1, vector<int>(Y+1, 0));
    dp[0][0] = 1;

    for(int i=0; i<=X; i++) {
        for(int j=0; j<=Y; j++) {
            if(i+1 <= X && j+2 <= Y) {
                dp[i+1][j+2] = (dp[i+1][j+2] + dp[i][j]) % MOD;
            }
            if(i+2 <= X && j+1 <= Y) {
                dp[i+2][j+1] = (dp[i+2][j+1] + dp[i][j]) % MOD;
            }
        }
    }

    cout << dp[X][Y] << endl;

    return 0;
}