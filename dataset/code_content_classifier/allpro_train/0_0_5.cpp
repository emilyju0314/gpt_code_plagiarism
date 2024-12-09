#include <iostream>
#include <vector>
#include <unordered_map>

const int MOD = 998244353;

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> arr(n);
    std::vector<int> last_pos(n+1, -1);
    std::vector<long long> dp(n+1, 0);

    for(int i=0; i<n; i++) {
        std::cin >> arr[i];
    }

    dp[0] = 1;
    long long curr_sum = 0;
    for (int i = 1; i <= n; i++) {
        int a = arr[i-1];
        if (last_pos[a] != -1 && i - last_pos[a] > k) { // If the number appeared before and was outside k-length segment
            curr_sum = (curr_sum - dp[last_pos[a]-1] + MOD) % MOD;
        }
        dp[i] = (curr_sum + dp[i-1]) % MOD; // Recurrence relation for dp[i]
        curr_sum = (curr_sum + dp[i]) % MOD;
        last_pos[a] = i;
    }

    std::cout << dp[n] << std::endl;
    
    return 0;
}