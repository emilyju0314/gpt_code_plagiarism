#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> animals(n, vector<int>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> animals[i][j];
        }
    }

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(k+1)));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            for(int l=1; l<=k; l++) {
                dp[i][j][l] = max(dp[i-1][j+l-1][l] + accumulate(animals[i-1].begin() + j - 1, animals[i-1].begin() + j + l - 1, 0), dp[i][j-1][l]);
            }
        }
    }

    cout << dp[n][m][k] << endl;

    return 0;
}