#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<vector<int>> dp(N, vector<int>(N, 0));

    for (int len = 1; len <= N; len++) {
        for (int i = 0; i + len - 1 < N; i++) {
            int j = i + len - 1;
            if ((N - len) % 2 == 0) {
                dp[i][j] = max(dp[i+1][j] + a[i], dp[i][j-1] + a[j]);
            } else {
                dp[i][j] = min(dp[i+1][j] - a[i], dp[i][j-1] - a[j]);
            }
        }
    }

    cout << dp[0][N-1] << endl;

    return 0;
}