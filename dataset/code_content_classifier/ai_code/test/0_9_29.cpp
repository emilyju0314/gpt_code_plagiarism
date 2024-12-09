#include <iostream>
#include <vector>

long long countNearlyFullSubsequences(std::vector<int>& arr, long long sum) {
    int n = arr.size();
    long long count = 0;
    for(int mask = 0; mask < (1 << n); mask++) {
        long long currentSum = 0;
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) {
                currentSum += arr[i];
            }
        }
        if(currentSum == sum - 1) {
            count++;
        }
    }
    return count;
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n;
        std::cin >> n;

        std::vector<int> arr(n);
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            std::cin >> arr[i];
            sum += arr[i];
        }

        std::cout << countNearlyFullSubsequences(arr, sum) << std::endl;
    }

    return 0;
}