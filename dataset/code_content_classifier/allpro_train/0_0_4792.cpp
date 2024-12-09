#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int N, M, i, j;
    cin >> N >> M >> i >> j;

    double dp[1001][1001] = {0};
    dp[N][j] = 0;

    for (int row = N-1; row >= i; row--) {
        for (int col = 1; col <= M; col++) {
            double total_moves = 0;
            if (col > 1) total_moves++;
            if (col < M) total_moves++;
            total_moves++; // moving down

            dp[row][col] = 1 + (dp[row+1][col-1] + dp[row+1][col] + dp[row+1][col+1]) / total_moves;
        }
    }

    cout << fixed << setprecision(10) << dp[i][j] << endl;

    return 0;
}