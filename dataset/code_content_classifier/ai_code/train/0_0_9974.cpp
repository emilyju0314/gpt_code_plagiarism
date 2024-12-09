#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> dp(s.size() + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= s.size(); i++) {
        dp[i] = dp[i-1];

        if (s[i-1] == 'm' || s[i-1] == 'w') {
            cout << 0 << endl;
            return 0;
        }

        if (i > 1 && (s[i-1] == 'n' || s[i-1] == 'u') && (s[i-2] == 'n' || s[i-2] == 'u')) {
            dp[i] += dp[i-2];
            dp[i] %= MOD;
        }
    }

    cout << dp[s.size()] << endl;

    return 0;
}