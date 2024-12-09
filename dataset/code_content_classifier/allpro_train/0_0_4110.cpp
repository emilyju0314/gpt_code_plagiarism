#include <iostream>
#include <string>
#include <vector>

#define MOD 1000000007

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    vector<int> dp(s.size() + 1, 0);
    vector<int> prefix(t.size(), 0);

    for(int i = t.size() - 1; i < s.size(); i++) {
        prefix[i % t.size()] = (s.substr(i - t.size() + 1, t.size()) == t) ? 1 : 0;
        dp[i + 1] = (dp[i] + prefix[i % t.size()]) % MOD;
    }

    long long int ans = 0;
    for(int i = 0; i < s.size(); i++) {
        ans = (ans + dp[i]) % MOD;
    }

    cout << ans << endl;

    return 0;
}