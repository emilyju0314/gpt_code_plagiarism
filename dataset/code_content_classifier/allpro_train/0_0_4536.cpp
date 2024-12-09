#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    
    for(int i=0; i<n; i++) {
        string row;
        cin >> row;
        for(int j=0; j<m; j++) {
            matrix[i][j] = row[j]-'0';
        }
    }

    vector<vector<int>> dp(n, vector<int>(m)); // dp[i][j] stores the maximum width of consecutive ones ending at position (i, j)
    int maxArea = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(matrix[i][j] == 1) {
                dp[i][j] = (j == 0 ? 1 : dp[i][j-1] + 1);
                int minHeight = dp[i][j];
                for(int k=i; k>=0; k--) {
                    minHeight = min(minHeight, dp[k][j]);
                    maxArea = max(maxArea, minHeight * (i - k + 1));
                }
            }
        }
    }

    cout << maxArea << endl;

    return 0;
}