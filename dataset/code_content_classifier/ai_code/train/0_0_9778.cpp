#include <iostream>
#include <vector>
#include <string>
#define MOD 1000000007

using namespace std;

int main() {
    int N;
    cin >> N;

    string s, t;
    cin >> s >> t;

    vector<int> dp(N+1, 0);
    dp[1] = 1;

    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i-1];
        if (s[i-1] != t[i-1]) {
            dp[i] = (dp[i] + 1) % MOD;
        }
    }

    cout << dp[N] << endl;

    return 0;
}