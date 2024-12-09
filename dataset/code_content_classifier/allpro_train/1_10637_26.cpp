#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

const int MAX_M = 7, MAX_B = 10, MAX_N = 1000;
int m,g,n;
int a[MAX_M], b[MAX_M];
int dp[MAX_M + 1][MAX_N + 1];

int main()
{
    while(cin >> m && m) {
        for(int i = 0; i < m; i++)
            cin >> a[i] >> b[i];

        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j <= MAX_N; j++) {
                for(int k = 0; k <= b[i]; k++) {
                    if(j + a[i] * k > 1000) continue;
                    dp[i+1][j+a[i]*k] += dp[i][j];
                }
            }
        }
        
        cin >> g;
        for(int k = 0; k < g; k++) {
            cin >> n;
            cout << dp[m][n] << endl;
        }

        
    }
}