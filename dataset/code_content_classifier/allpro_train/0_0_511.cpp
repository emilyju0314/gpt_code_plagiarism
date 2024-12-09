#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#define MOD 1000000007

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> S(N);
    unordered_map<string, int> cnt;

    for (int i = 0; i < N; i++) {
        cin >> S[i];
        cnt[S[i]] = 1;
    }

    string t;
    cin >> t;

    vector<long long> dp(t.size() + 1);
    dp[0] = 1;

    for (int i = 0; i < t.size(); i++) {
        for (int j = 0; j < N; j++) {
            int len = S[j].size();

            if (i + len <= t.size() && t.substr(i, len) == S[j]) {
                dp[i + len] += dp[i];
                dp[i + len] %= MOD;
            }
        }
    }

    cout << dp[t.size()] << endl;

    return 0;
}