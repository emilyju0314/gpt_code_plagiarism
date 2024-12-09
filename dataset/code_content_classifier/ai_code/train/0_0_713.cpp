#include <iostream>
#include <stack>
#include <cstring>

#define MOD 1000000007

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    long long dp[n+1][n+1][3][3];
    memset(dp, 0, sizeof(dp));

    stack<int> st;

    for(int i = 0; i < n; i++) {
        if(s[i] == '(')
            st.push(i);
        else {
            dp[i][i][0][1] = dp[i][i][1][0] = dp[i][i][0][2] = dp[i][i][2][0] = 1;
            int j = st.top();
            st.pop();
            for(int a = 0; a < 3; a++) {
                for(int b = 0; b < 3; b++) {
                    if(a != 0 || b != 0)
                        dp[j][i][1][2] += dp[j+1][i-1][a][b];
                    dp[j][i][1][2] %= MOD;
                    if(a != 1 || b != 1)
                        dp[j][i][0][2] += dp[j+1][i-1][a][b];
                    dp[j][i][0][2] %= MOD;
                    if(a != 2 || b != 2)
                        dp[j][i][0][1] += dp[j+1][i-1][a][b];
                    dp[j][i][0][1] %= MOD;
                    if(a != 0 || b != 0)
                        dp[j][i][2][1] += dp[j+1][i-1][a][b];
                    dp[j][i][2][1] %= MOD;
                }
            }

            for(int x = j; x < i; x++) {
                for(int a = 0; a < 3; a++) {
                    for(int b = 0; b < 3; b++) {
                        if(a != 0 || b != 0)
                            dp[j][i][1][1] += (dp[j][x][1][a] * dp[x+1][i][b][0] % MOD);
                        dp[j][i][1][1] %= MOD;
                        if(a != 1 || b != 1)
                            dp[j][i][0][0] += (dp[j][x][0][a] * dp[x+1][i][b][1] % MOD);
                        dp[j][i][0][0] %= MOD;
                        if(a != 2 || b != 2)
                            dp[j][i][2][2] += (dp[j][x][2][a] * dp[x+1][i][b][2] % MOD);
                        dp[j][i][2][2] %= MOD;
                    }
                }
            }
        }
    }

    long long ans = 0;
    for(int a = 0; a < 3; a++) {
        for(int b = 0; b < 3; b++) {
            ans += dp[0][n-1][a][b];
            ans %= MOD;
        }
    }

    cout << ans << endl;

    return 0;
}