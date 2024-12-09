#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 3005;
long long dp[MAX_N][MAX_N];

int main() {
    int N, M;
    cin >> N >> M;

    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        dp[i][0] = dp[i-1][0] * 2 % M;
        for (int j = 1; j <= i; j++) {
            dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % M;
        }
    }

    long long ans = 0;
    for (int i = 0; i <= N; i++) {
        long long tmp = dp[N][i] * dp[N][i] % M;
        if (i % 2 == 0) {
            ans = (ans + tmp) % M;
        } else {
            ans = (ans - tmp + M) % M;
        }
    }

    cout << ans << endl;

    return 0;
}