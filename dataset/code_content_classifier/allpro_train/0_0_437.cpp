#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    int n, m, k, c, d;
    cin >> n >> m >> k >> c >> d;

    vector<int> a(k);
    for(int i=0; i<k; i++) {
        cin >> a[i];
    }

    vector<vector<int>> streets(m, vector<int>(2));
    for(int i=0; i<m; i++) {
        cin >> streets[i][0] >> streets[i][1];
    }

    // Initialize dp array
    vector<vector<vector<int>>> dp(101, vector<vector<int>>(n+1, vector<int>(k+1, INF)));
    dp[0][1][0] = 0;

    // Dynamic programming
    for(int i=0; i<=100; i++) {
        for(int j=1; j<=n; j++) {
            for(int l=0; l<=k; l++) {
                if(dp[i][j][l] < INF) {
                    for(int p=0; p<m; p++) {
                        int new_j = (j==streets[p][0]) ? streets[p][1] : streets[p][0];
                        dp[i+1][new_j][l] = min(dp[i+1][new_j][l], dp[i][j][l] + c + l*d);

                        if(new_j == 1 && l+1 <= k) {
                            dp[i+1][1][l+1] = min(dp[i+1][1][l+1], dp[i][j][l]);
                        }
                    }
                }
            }
        }
    }

    int ans = INF;
    for(int l=0; l<=k; l++) {
        ans = min(ans, dp[100][1][l]);
    }

    cout << ans << endl;

    return 0;
}