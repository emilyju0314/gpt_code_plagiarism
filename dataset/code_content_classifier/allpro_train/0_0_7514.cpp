#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    vector<long long> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    vector<long long> dp(N+1, 0);
    dp[0] = 1;

    int j = 0;
    for (int i = 1; i <= N; i++) {
        while (j < i && S[i-1] - S[j] >= A) {
            j++;
        }
        if (i - j <= 1) {
            dp[i] = dp[i-1];
        } else {
            dp[i] = (dp[i-1] + dp[j]) % MOD;
        }
    }

    long long ans = 0;
    j = 0;
    for (int i = 1; i <= N; i++) {
        while (j < i && S[i-1] - S[j] >= B) {
            j++;
        }
        ans = (ans + dp[i] - dp[j] + MOD) % MOD;
    }

    cout << ans << endl;

    return 0;
}