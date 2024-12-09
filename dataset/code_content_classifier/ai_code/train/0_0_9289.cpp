#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSimilarity(string A, string B) {
    int n = A.size();
    int m = B.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (A[i-1] == B[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int maxScore = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            maxScore = max(maxScore, 4 * dp[i][j] - i - j);
        }
    }

    return maxScore;
}

int main() {
    int n, m;
    cin >> n >> m;

    string A, B;
    cin >> A >> B;

    cout << maxSimilarity(A, B) << endl;

    return 0;
}