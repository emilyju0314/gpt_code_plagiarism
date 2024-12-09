#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int matrixChainMultiplication(vector<int>& arr) {
    int n = arr.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i < n - len + 1; ++i) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + arr[i] * arr[k + 1] * arr[j + 1]);
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    int n;
    cin >> n;

    vector<int> dimensions(n + 1);
    for (int i = 0; i <= n; ++i) {
        cin >> dimensions[i];
    }

    cout << matrixChainMultiplication(dimensions) << endl;

    return 0;
}