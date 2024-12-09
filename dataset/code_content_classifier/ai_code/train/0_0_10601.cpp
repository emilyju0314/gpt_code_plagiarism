#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            matrix[i][j] = row[j] - '0';
        }
    }

    vector<vector<int>> dp(n, vector<int>(m, 0));
    int maxArea = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || matrix[i][j] == 0) {
                dp[i][j] = matrix[i][j];
            } else {
                dp[i][j] = dp[i-1][j] + 1;
            }
        }

        vector<int> sortedRow = dp[i];
        sort(sortedRow.begin(), sortedRow.end(), greater<int>());

        for (int j = 0; j < m; j++) {
            maxArea = max(maxArea, sortedRow[j] * (j + 1));
        }
    }

    cout << maxArea << endl;

    return 0;
}