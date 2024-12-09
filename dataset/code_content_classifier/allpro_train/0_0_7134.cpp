#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector<vector<int>> dp(n, vector<int>(2, 0)); // dp[i][j] represents the maximum joy of feeding hares 1 to i with hare i being in state j (0 for hungry, 1 for full)

    dp[0][0] = a[0]; // feeding the first hare in the hungry state
    dp[0][1] = b[0]; // feeding the first hare in the full state

    // filling the dp table
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + a[i];
        dp[i][1] = max(dp[i - 1][0] + b[i], dp[i - 1][1] + c[i]);
    }

    int result = max(dp[n - 1][0], dp[n - 1][1]);
    cout << result << endl;

    return 0;
}