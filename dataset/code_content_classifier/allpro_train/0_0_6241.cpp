#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;
    
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    
    long long totalCost = 0;
    
    std::vector<int> differences;
    for (int i = 1; i < n; i++) {
        differences.push_back(arr[i] - arr[i - 1]);
    }
    
    std::sort(differences.begin(), differences.end(), std::greater<int>());
    
    for (int i = k - 1; i < n - 1; i++) {
        totalCost += differences[i];
    }
    
    std::cout << totalCost << std::endl;
    
    return 0;
}