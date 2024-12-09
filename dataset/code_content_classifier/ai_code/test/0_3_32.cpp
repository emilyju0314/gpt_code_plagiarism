#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            if (i > 0 && a[i] > a[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            }
        }

        int ans = 1;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[i]);
        }

        cout << ans << endl;
    }

    return 0;
}