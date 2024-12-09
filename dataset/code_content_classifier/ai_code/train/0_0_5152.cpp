#include <iostream>
#include <vector>

using namespace std;

int minSecondsToDestroy(int n, vector<int>& gemstones) {
    int dp[n][n] = {0};

    for(int i = n-1; i >= 0; i--) {
        for(int j = i; j < n; j++) {
            dp[i][j] = (gemstones[i] == gemstones[j]) ? ((j-i < 2) ? 0 : dp[i+1][j-1]) : n;
            for(int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]);
            }
        }
    }

    return dp[0][n-1];
}

int main() {
    int n;
    cin >> n;

    vector<int> gemstones(n);
    for(int i = 0; i < n; i++) {
        cin >> gemstones[i];
    }

    int minSeconds = minSecondsToDestroy(n, gemstones);

    cout << minSeconds << endl;

    return 0;
}