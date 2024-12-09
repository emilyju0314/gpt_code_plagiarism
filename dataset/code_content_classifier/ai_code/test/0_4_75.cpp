#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<vector<int>> dp(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        dp[i][i] = 1;
    }

    for (int len = 2; len <= N; len++) {
        for (int i = 0; i <= N - len; i++) {
            int j = i + len - 1;
            dp[i][j] = max(A[i] - dp[i+1][j], A[j] - dp[i][j-1]);
        }
    }

    if (dp[0][N-1] > 0) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }

    return 0;
}