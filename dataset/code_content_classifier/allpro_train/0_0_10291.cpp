#include <iostream>
#include <vector>
#include <unordered_map>

#define MOD 1000000007

int main() {
    int n, k;
    std::cin >> n >> k;
    
    std::vector<int> a(n);
    for(int i=0; i<n; i++) {
        std::cin >> a[i];
    }
    
    std::unordered_map<int, int> freq;
    
    // Count frequency of each element in array a
    for(int num : a) {
        freq[num]++;
    }
    
    std::vector<int> dp(256, 0);
    dp[0] = 1;
    
    // Iterating through all elements in the frequency map
    for(auto it : freq) {
        int num = it.first;
        int count = it.second;
        
        // Dynamic programming to calculate the number of ways to form XOR equal to k
        for(int i=0; i<count; i++) {
            for(int j=k; j>=num; j--) {
                dp[j] = (dp[j] + dp[j-num]) % MOD;
            }
        }
    }
    
    std::cout << dp[k] << std::endl;
    
    return 0;
}