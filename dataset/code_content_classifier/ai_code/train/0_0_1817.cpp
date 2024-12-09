#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;

int main() {
    int N;
    while (cin >> N) {
        if (N == 0) {
            break;
        }

        vector<int> prefRoom(N + 1), c(N + 1), dp(N + 2);
        for (int i = 1; i <= N; i++) {
            cin >> prefRoom[i];
            c[prefRoom[i]]++;
        }

        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= N; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
        }

        int ans = 1;
        for (int i = 1; i <= N; i++) {
            if (c[i] == 0) {
                continue;
            }

            for (int j = 0; j < c[i]; j++) {
                ans = (ans * dp[c[i]]) % MOD;
            }
        }

        cout << ans << endl;
    }

    return 0;
}