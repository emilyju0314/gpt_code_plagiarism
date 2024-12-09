#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double dp[51][51][51] = {};

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> rooms(m);
    for(int i = 0; i < m; i++) {
        cin >> rooms[i];
    }
    
    dp[0][0][0] = 1;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            for(int k = 0; k < m; k++) {
                if(dp[i][j][k] == 0) continue;
                for(int x = 0; x <= min(n - i, rooms[k]); x++) {
                    dp[i + x][max(j, x)][k] += dp[i][j][k] / rooms[k];
                }
            }
        }
    }
    
    double ans = 0;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j < m; j++) {
            ans += dp[n][i][j] * (i + 0.0) / (n + 0.0);
        }
    }
    
    cout << fixed;
    cout.precision(20);
    cout << ans << endl;
    
    return 0;
}