#include <iostream>
#include <vector>

using namespace std;

int calculateXOR(int n, int p, int q) {
    vector<vector<int>> dp(131, vector<int>(2000001));

    for (int i = 1; i <= 130; i++) {
        for (int j = 1; j <= min(i, 2000000); j++) {
            dp[i][j] = dp[i-1][j] ^ dp[i][j-1] ^ dp[i-1][j-1];
        }
    }

    return dp[p][q];
}

int main() {
    int n, p, q;
    cin >> n >> p >> q;

    int result = calculateXOR(n, p, q);
    cout << result << endl;

    return 0;
}