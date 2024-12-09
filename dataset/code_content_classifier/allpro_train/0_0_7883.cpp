#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int INF = 1e9;
int dp[2001][2001][8]; // Dynamic programming table

int main() {
    int n, k;
    cin >> n >> k;
    vector<string> matrix(n);
    for(int i = 0; i < n; i++) {
        cin >> matrix[i];
    }

    memset(dp, INF, sizeof dp);
    dp[0][0][0] = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= k; j++) {
            for(int c = 0; c <= 1; c++) {
                dp[i+1][j][0] = min(dp[i+1][j][0], dp[i][j][c]);

                int cost = c ? (matrix[i][n-1] != 'a') : 0;
                dp[i+1][j+cost][1] = min(dp[i+1][j+cost][1], dp[i][j][c] + cost);

                for(int m = 1; m < n; m++) {
                    cost = (matrix[i][m-1] != 'a') + (matrix[i][m] != 'a');
                    dp[i+1][j+cost][m%2] = min(dp[i+1][j+cost][m%2], dp[i][j][c] + cost);
                }
            }
        }
    }

    int ans = INF;
    for(int i = 0; i <= k; i++) {
        for(int j = 0; j < 2; j++) {
            ans = min(ans, dp[n][i][j]);
        }
    }

    string res = "";
    int cur = ans;
    int idx = 0, pos = 0;
    while(idx < n+n-1) {
        int cost = 0;
        if(pos == n-1) {
            cost = (matrix[idx][pos] != 'a');
            pos++;
        } else {
            cost = (matrix[idx][pos] != 'a') + (matrix[idx][pos+1] != 'a');
            pos += 2;
        }

        if(cur == dp[idx+1][k-cost][idx%2] + cost) {
            res += 'a';
            cur -= cost;
        } else {
            res += matrix[idx][idx%2];
        }
        idx++;
    }

    cout << res << endl;

    return 0;
}