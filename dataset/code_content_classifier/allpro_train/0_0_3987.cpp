#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> hills(n);
    for(int i = 0; i < n; i++) {
        cin >> hills[i];
    }

    int k = (n + 1) / 2;
    vector<int> dp(n+1, 0); // dp[i] stores the minimum number of hours required to build i houses

    for(int i = 0; i < n; i++) {
        vector<int> next_dp(n+1, INT_MAX);
        for(int j = 0; j <= min(k, i+1); j++) {
            if (j == 0) {
                next_dp[j] = dp[j];
                continue;
            }
            next_dp[j] = min(next_dp[j], dp[j]);
            if (i > 0 && j > 0 && hills[i] >= hills[i-1]) {
                next_dp[j] = min(next_dp[j], dp[j-1] + hills[i] - hills[i-1] + 1);
            }
        }
        dp = next_dp;
    }

    for(int i = 0; i < k; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;

    return 0;
}