#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, d;
    cin >> n >> m >> d;

    vector<int> dp(n + 1, -1e9); // Initialize DP array with large negative values
    dp[1] = 0; // Base case

    for(int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;

        vector<int> new_dp(n + 1, -1e9); // Temporary DP array to store updated values
        
        for(int j = 1; j <= n; j++) {
            for(int k = max(1, j - d); k <= min(n, j + d); k++) {
                new_dp[k] = max(new_dp[k], dp[j] + b - abs(a - k));
            }
        }

        dp = new_dp; // Update DP array with new values
    }

    cout << *max_element(dp.begin(), dp.end()) << endl; // Output the maximum happiness value

    return 0;
}