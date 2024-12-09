#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 2001;
const int MAX_M = 1000000007;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> dp(N + 1, vector<int>(3*N + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 3*N; j++) {
            dp[i][j] = (dp[i][j-1] + dp[i-1][j-1]) % M;
            if (j >= 3) {
                dp[i][j] = (dp[i][j] - dp[i-1][j-3] + M) % M;
            }
        }
    }

    int result = dp[N][3*N];
    cout << result << endl;

    return 0;
}