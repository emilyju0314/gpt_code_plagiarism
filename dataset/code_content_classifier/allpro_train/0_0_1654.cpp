#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> skills(n);
    for (int i = 0; i < n; i++) {
        cin >> skills[i];
    }

    sort(skills.begin(), skills.end());

    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i-1][j];
            int cnt = 0;
            for (int p = i; p > 0; p--) {
                if (skills[i-1] - skills[p-1] <= 5) {
                    cnt++;
                    dp[i][j] = max(dp[i][j], dp[p-1][j-1] + cnt);
                }
            }            
        }
    }

    cout << dp[n][k] << endl;

    return 0;
}