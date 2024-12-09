#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, A;
    cin >> N >> A;

    vector<int> x(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }

    vector<vector<long long>> dp(N + 1, vector<long long>(2500, 0));
    dp[0][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = N; j >= 1; j--) {
            for (int k = 2500 - 1; k >= x[i]; k--) {
                dp[j][k] += dp[j - 1][k - x[i]];
            }
        }
    }

    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += dp[i][i * A];
    }

    cout << ans << endl;

    return 0;
}