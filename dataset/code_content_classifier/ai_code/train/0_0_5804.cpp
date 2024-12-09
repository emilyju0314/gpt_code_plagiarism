#include <iostream>
#include <vector>
#include <unordered_map>

#define MOD 1000000007

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    
    std::unordered_map<int, long long> count, last, dp;
    
    long long result = 0;
    long long pref = 0;
    
    for(int i = 0; i < n; i++) {
        pref = (pref + dp[arr[i]] - last[arr[i]] + MOD) % MOD;
        dp[arr[i]] = (dp[arr[i]] + pref) % MOD;
        result = (result + pref) % MOD;
        last[arr[i]] = dp[arr[i]];
    }
    
    std::cout << result << std::endl;
    
    return 0;
}