#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        long long N, A, B, C, D;
        cin >> N >> A >> B >> C >> D;

        // Initialize a vector to store the minimum costs to reach numbers up to N
        vector<long long> dp(N+1, 0);
        
        for (int j = 1; j <= N; j++) {
            dp[j] = dp[j-1] + D; // Increasing or decreasing the number by 1
            
            if (j % 2 == 0) dp[j] = min(dp[j], dp[j/2] + A); // Multiply by 2
            if (j % 3 == 0) dp[j] = min(dp[j], dp[j/3] + B); // Multiply by 3
            if (j % 5 == 0) dp[j] = min(dp[j], dp[j/5] + C); // Multiply by 5
        }

        cout << dp[N] << endl;
    }

    return 0;
}