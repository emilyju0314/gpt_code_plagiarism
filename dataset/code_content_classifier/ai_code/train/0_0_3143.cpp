#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

int countSubsets(vector<int>& arr, int n, int t, int m) {
    vector<vector<int>> dp(t+1, vector<int>(m+1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= t; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= arr[i-1]) {
                dp[i][j] = (dp[i][j] + dp[i-1][j-arr[i-1]]) % MOD;
            }
        }
    }

    vector<int> valid(m+1, 0);
    valid[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= arr[i-1]; j--) {
            valid[j] = (valid[j] + valid[j-arr[i-1]]) % MOD;
        }
    }

    int ans = 0;
    for (int i = 1; i <= m; i++) {
        if (valid[i] == 0) {
            ans = (ans + dp[t][i]) % MOD;
        }
    }

    return ans;
}

int main() {
    int n, m, t;
    cin >> n >> m >> t;

    vector<int> arr(t);
    for (int i = 0; i < t; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int result = countSubsets(arr, n, t, m);
    cout << result << endl;

    return 0;
}