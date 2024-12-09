#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> arr(n);
    int sum = 0;
    
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
        sum += arr[i];
    }
    
    int avg = sum / n;
    int max_changes = 0;
    
    for (int i = 0; i < n; i++) {
        max_changes += std::max(0, arr[i] - avg);
    }
    
    std::cout << max_changes << std::endl;
    
    return 0;
}