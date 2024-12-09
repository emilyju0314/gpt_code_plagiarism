#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> roadPerishability(n, vector<int>(n, 0));
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n-i; j++) {
            cin >> roadPerishability[i-1][j];
        }
    }

    for(int i = 0; i < n; i++) {
        dp[n-1][i] = 0;
    }

    for(int i = n-2; i >= 0; i--) {
        for(int j = 0; j < n-i; j++) {
            dp[i][j] = min(dp[i+1][j]+roadPerishability[i][j], dp[i+1][j+1]+roadPerishability[i][j]);
        }
    }

    for(int i = 0; i < n; i++) {
        cout << dp[0][i] << endl;
    }

    return 0;
}