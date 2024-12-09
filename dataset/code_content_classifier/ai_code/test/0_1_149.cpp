#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        long long x;
        cin >> n >> k >> x;

        string s;
        cin >> s;

        vector<long long> dp(n+1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i-1];
            if (s[i-1] == '*') {
                dp[i] += dp[i-1];
            }
        }

        string ans;
        for (int i = n; i > 0; i--) {
            if (s[i-1] == '*') {
                if (x <= dp[i-1]) {
                    ans.push_back('a');
                } else {
                    ans.push_back('b');
                    x -= dp[i-1];
                }
            } else {
                ans.push_back(s[i-1]);
            }
        }

        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }

    return 0;
}