#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, X, D;
    cin >> N >> X >> D;

    vector<int> m(N+1);
    vector<int> p(N+1);

    for(int i = 1; i <= N; i++) {
        cin >> m[i] >> p[i];
    }

    vector<long long> dp(X+1, -1);
    dp[0] = 0;

    for(int i = 1; i <= N; i++) {
        vector<long long> next_dp(X+1, -1);

        for(int j = 0; j <= X; j++) {
            if(dp[j] >= 0) {
                long long max_c = min((X - j) / D, (dp[j] / m[i]));
                for(long long c = 0; c <= max_c; c++) {
                    long long remaining_Moto = dp[j] - c * m[i];
                    long long next_j = j + c * D;
                    long long next_c = dp[j] + c;
                    next_dp[next_j] = max(next_dp[next_j], next_c);
                }
            }
        }

        dp = next_dp;
    }

    long long ans = 0;
    for(int i = 0; i <= X; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;

    return 0;
}