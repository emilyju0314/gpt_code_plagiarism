#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }

        vector<string> grid(n);
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }

        int maxSide = 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '*') {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = 1;
                    if (i > 0 && j > 0) {
                        dp[i][j] += min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                    }
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }

        cout << maxSide << endl;
    }

    return 0;
}