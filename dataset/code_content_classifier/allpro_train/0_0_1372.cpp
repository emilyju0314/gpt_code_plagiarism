#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> A(2, vector<int>(N));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    vector<int> dp(N, 0);
    dp[0] = A[0][0];
    for (int j = 1; j < N; j++) {
        dp[j] = dp[j - 1] + A[0][j];
    }

    for (int i = 1; i < 2; i++) {
        vector<int> temp(N, 0);
        temp[0] = dp[0] + A[i][0];
        for (int j = 1; j < N; j++) {
            temp[j] = max(temp[j - 1], dp[j]) + A[i][j];
        }
        dp = temp;
    }

    cout << dp[N - 1] << endl;

    return 0;
}