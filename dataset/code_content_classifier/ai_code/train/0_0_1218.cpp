#include <iostream>
#include <vector>
#include <algorithm>

int lis_max_sum(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> dp(n, 0);
    
    for (int i = 0; i < n; ++i) {
        dp[i] = nums[i];
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = std::max(dp[i], dp[j] + nums[i]);
            }
        }
    }
    
    return *std::max_element(dp.begin(), dp.end());
}

int main() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }
    
    int result = lis_max_sum(A);
    
    std::cout << result << std::endl;
    
    return 0;
}