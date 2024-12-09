#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(n));
    dp[0][0] = matrix[0][0];

    for(int i = 1; i < n; i++) {
        dp[0][i] = dp[0][i-1] * matrix[0][i];
        dp[i][0] = dp[i-1][0] * matrix[i][0];
    }

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) * matrix[i][j];
        }
    }

    int zeros = 0;
    vector<char> path(n + n - 2);
    int row = n - 1, col = n - 1;
    for(int i = n + n - 3; i >= 0; i--) {
        if(row > 0 && (col == 0 || dp[row-1][col] < dp[row][col-1])) {
            path[i] = 'D';
            row--;
        } else {
            path[i] = 'R';
            col--;
        }
    }

    cout << __builtin_ctz(dp[n-1][n-1]) << endl;
    for(char c : path) {
        cout << c;
    }
    cout << endl;

    return 0;
}