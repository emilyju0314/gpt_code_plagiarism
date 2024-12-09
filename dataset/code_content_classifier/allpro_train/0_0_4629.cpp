#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    vector<int> gems(30001, 0); // Initialize gems vector with 0's
    for (int i = 0; i < n; i++) {
        int gemLocation;
        cin >> gemLocation;
        gems[gemLocation]++;
    }

    vector<int> dp(30001, 0); // Initialize dp vector with 0's
    dp[d] = gems[d]; // Set the number of gems at island d
    int maxGems = dp[d]; // Initialize maxGems with the number of gems at island d

    for (int i = d+1; i <= 30000; i++) {
        dp[i] = max(dp[i], gems[i] + dp[i-d]); // Update dp[i] with the maximum number of gems
        maxGems = max(maxGems, dp[i]); // Update maxGems with the maximum number of gems
    }

    cout << maxGems << endl;

    return 0;
}