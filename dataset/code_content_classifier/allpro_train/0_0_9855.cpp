#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#define MOD 1000000007
using namespace std;

int main() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    vector<int> last(26, -1);
    vector<int> dp(N+1, 0);
    dp[0] = 1;

    for (int i = 1; i <= N; i++) {
        dp[i] = (2 * dp[i-1]) % MOD;
        if (last[S[i-1] - 'a'] != -1) {
            dp[i] = (dp[i] - dp[last[S[i-1] - 'a']] + MOD) % MOD;
        }
        last[S[i-1] - 'a'] = i - 1;
    }

    cout << dp[N] << endl;

    return 0;
}