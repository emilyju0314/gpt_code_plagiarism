#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<int> dp(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        if (s[i - 1] == '2' && i >= 4 && s[i - 2] == '0' && s[i - 3] == '1' && s[i - 4] == '7') {
            dp[i]++;
        }
    }

    while (q--) {
        int ai, bi;
        cin >> ai >> bi;
        int ugliness = dp[bi] - dp[ai - 1];

        if (bi - ai + 1 >= 4 && ugliness == 0) {
            cout << -1 << endl;
        } else {
            cout << bi - ai + 1 - ugliness << endl;
        }
    }

    return 0;
}