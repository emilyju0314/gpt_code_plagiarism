#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

#define MOD 998244353

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> heights(2 * N);
    for (int i = 0; i < 2 * N; i++) {
        cin >> heights[i];
    }

    sort(heights.begin(), heights.end());

    unordered_map<int, int> dp;
    dp[0] = 1;

    for (int i = 1; i < 2 * N; i++) {
        unordered_map<int, int> new_dp;

        for (auto& pair : dp) {
            int current_height = pair.first;
            int count = pair.second;

            new_dp[current_height] = (new_dp[current_height] + count) % MOD;

            if (heights[i] != current_height) {
                new_dp[heights[i]] = (new_dp[heights[i]] + count) % MOD;
            } else {
                new_dp[heights[i]] = (new_dp[heights[i]] + dp[current_height]) % MOD;
            }

            new_dp[__gcd(heights[i], current_height)] = (new_dp[__gcd(heights[i], current_height)] + count) % MOD;
        }

        dp = new_dp;
    }

    int result = dp[0];
    cout << result << "\n";

    return 0;
}