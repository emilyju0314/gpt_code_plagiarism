#include <iostream>
#include <vector>

long long countNearlyFullSubsequences(std::vector<int>& arr) {
    long long sum = 0;
    for (int num : arr) {
        sum += num;
    }
    
    long long count = 0;
    for (int i = 0; i < (1 << arr.size()); ++i) {
        long long curSum = 0;
        for (int j = 0; j < arr.size(); ++j) {
            if (i & (1 << j)) {
                curSum += arr[j];
            }
        }
        if (curSum == sum - 1) {
            count++;
        }
    }
    
    return count;
}

int main() {
    int t;
    std::cin >> t;
    
    while (t--) {
        int n;
        std::cin >> n;
        
        std::vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> arr[i];
        }
        
        long long ans = countNearlyFullSubsequences(arr);
        std::cout << ans << std::endl;
    }
    
    return 0;
}