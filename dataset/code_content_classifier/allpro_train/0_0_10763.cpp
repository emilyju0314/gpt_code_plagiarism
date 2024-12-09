#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> cannons(n, vector<pair<int, int>>(n, {INT_MAX, INT_MAX}));

    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cannons[a][b] = {1, c};
    }

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, INT_MAX)));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(i == j) dp[i][j][k] = 0;
                else dp[i][j][k] = k == j ? 0 : cannons[i][j].second;

                for(int l = 0; l < n; l++) {
                    dp[i][j][k] = min(dp[i][j][k], dp[i][j][l] + dp[i][l][k]);
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int minTime = INT_MAX;
            for(int k = 0; k < n; k++) {
                minTime = min(minTime, dp[i][j][k]);
            }

            cout << minTime << " ";
        }
        cout << endl;
    }

    return 0;
}