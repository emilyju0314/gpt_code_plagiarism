#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    vector<int> dp(n, 1);

    for (int i = 0; i < n; i++) {
        if (s[i] != s[(i+1)%n]) {
            dp[i] = 2;
        }
    }

    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;

    return 0;
}