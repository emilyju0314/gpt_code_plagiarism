#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000009;

int main() {
    int n, w, b;
    cin >> n >> w >> b;

    // Initialize a 3D DP table to store the number of ways to achieve each state
    vector<vector<vector<long long>> dp(n, vector<vector<long long>>(w+1, vector<long long>(b+1, 0)));

    // Base case: there is only 1 way to form the first day
    dp[0][1][0] = dp[0][0][1] = 1;

    // Iterate over the remaining days
    for (int i = 1; i < n; i++) {
        for (int gw = 0; gw <= w; gw++) {
            for (int gb = 0; gb <= b; gb++) {
                // Add ways to form the next day after a white stripe
                if (gw > 0) {
                    dp[i][gw][gb] = (dp[i][gw][gb] + dp[i-1][gw-1][gb]) % MOD;
                }
                
                // Add ways to form the next day after a black stripe
                if (gb > 0) {
                    dp[i][gw][gb] = (dp[i][gw][gb] + dp[i-1][gw][gb-1]) % MOD;
                }
            }
        }
    }

    // Calculate total number of ways
    long long total_ways = 0;
    for (int gw = 0; gw <= w; gw++) {
        for (int gb = 0; gb <= b; gb++) {
            // Check if the current state is valid (contains all n days)
            if (gw + gb == n) {
                total_ways = (total_ways + dp[n-1][gw][gb]) % MOD;
            }
        }
    }

    cout << total_ways << endl;

    return 0;
}