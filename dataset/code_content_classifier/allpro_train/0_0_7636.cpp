#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, h, l, r;
    cin >> n >> h >> l >> r;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(h, -1));
    dp[0][0] = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < h; j++) {
            if(dp[i][j] != -1) {
                int sleep_time = (j + a[i]) % h;
                dp[i + 1][sleep_time] = max(dp[i + 1][sleep_time], dp[i][j] + (l <= sleep_time && sleep_time <= r));

                sleep_time = (j + a[i] - 1) % h;
                dp[i + 1][sleep_time] = max(dp[i + 1][sleep_time], dp[i][j] + (l <= sleep_time && sleep_time <= r));
            }
        }
    }

    int ans = 0;
    for(int j = 0; j < h; j++) {
        ans = max(ans, dp[n][j]);
    }

    cout << ans << endl;

    return 0;
}