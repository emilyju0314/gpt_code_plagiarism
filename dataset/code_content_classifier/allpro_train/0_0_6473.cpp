#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    string s;
    cin >> s;

    int n = s.size();
    vector<long long> dp(n, 0);
    dp[0] = (s[0] == '?' ? 2 : 1);

    for (int i = 1; i < n; ++i) {
        dp[i] = dp[i - 1] * (s[i] == '?' ? 2 : 1) % MOD;
    }

    long long answer = 1;
    int cnt = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '1') {
            ++cnt;
        } else if (s[i] == '0') {
            answer = (answer * max(1LL, dp[i] * cnt)) % MOD;
            cnt = max(0, cnt - 1);
        }
    }

    cout << answer << endl;

    return 0;
}