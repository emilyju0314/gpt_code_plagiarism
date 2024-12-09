#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    
    long long totalPoints = 0;
    for(int i = 1; i < n-1; i++) {
        totalPoints += std::min(arr[i], std::min(arr[i-1], arr[i+1]));
    }
    
    totalPoints += std::min(arr[0], arr[1]);
    totalPoints += std::min(arr[n-1], arr[n-2]);
    
    std::cout << totalPoints << std::endl;
    
    return 0;
}