#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int N, K;
vector<int> A, B;

int main() {
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        A.push_back(a);
        B.push_back(b);
    }

    int dp[N + 1][N + 1];
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= i / 2; j++) {
            dp[i][j] = (dp[i - 1][j] + (j ? dp[i - 1][j - 1] : 0)) % MOD;
        }
    }

    int ans = 0;
    for (int i = 0; i <= N; i++) {
        ans = (ans + 1LL * dp[N][i] * (i + 1)) % MOD;
    }

    cout << ans << endl;

    return 0;
}