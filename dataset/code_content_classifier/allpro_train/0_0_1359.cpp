#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> games(n);
    for (int i = 0; i < n; i++) {
        cin >> games[i];
    }

    int dp[n];
    dp[0] = games[0];
    if (n > 1) {
        dp[1] = max(games[0], games[1]);
    }

    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + games[i]);
    }

    cout << dp[n-1] << endl;

    return 0;
}