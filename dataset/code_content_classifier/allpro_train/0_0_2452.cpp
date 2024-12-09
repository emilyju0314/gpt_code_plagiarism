#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++) {
        if (s[i] >= s[i-1]) {
            dp[i] = dp[i-1] + 1;
        }
    }

    while (m--) {
        string query;
        cin >> query;

        if (query == "count") {
            int ans = *max_element(dp.begin(), dp.end());
            cout << ans << endl;
        } else {
            int l, r;
            cin >> l >> r;
            l--; r--;
            for (int i = l; i <= r; i++) {
                if (s[i] == '4') {
                    s[i] = '7';
                } else {
                    s[i] = '4';
                }
                if (i > 0) {
                    if (s[i] >= s[i-1]) {
                        dp[i] = dp[i-1] + 1;
                    } else {
                        dp[i] = dp[i-1];
                    }
                }
            }
        }
    }

    return 0;
}