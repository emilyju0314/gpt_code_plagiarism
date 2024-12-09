#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countOperations(vector<string>& matrix, int n, int m) {
    vector<vector<int>> dp(n, vector<int>(m, 0));

    // Initialize the dp matrix to store the number of operations needed to make a portal sub-rectangle
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '1') {
                dp[i][j] = 1;
            }
        }
    }

    // Calculate the accumulated number of operations needed for each block
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }

    int minOperations = INT_MAX;
    for (int a = 5; a <= n; a++) {
        for (int b = 4; b <= m; b++) {
            for (int i = a - 1; i < n; i++) {
                for (int j = b - 1; j < m; j++) {
                    int operations = dp[i][j] - dp[i - a][j] - dp[i][j - b] + dp[i - a][j - b];
                    minOperations = min(minOperations, operations);
                }
            }
        }
    }

    return minOperations;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<string> matrix(n);

        for (int i = 0; i < n; i++) {
            cin >> matrix[i];
        }

        int minOperations = countOperations(matrix, n, m);
        cout << minOperations << endl;
    }

    return 0;
}