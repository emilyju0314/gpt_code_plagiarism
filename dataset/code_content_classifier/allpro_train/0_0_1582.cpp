#include <iostream>
#include <vector>
#include <algorithm>

bool possibleToReorder(int n, int m, std::vector<int>& arr) {
    std::sort(arr.begin(), arr.end(), std::greater<int>());
    
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i] / (i + 1);
        if(sum > m) {
            return false;
        }
    }
    
    return sum == m;
}

int main() {
    int t;
    std::cin >> t;
    
    while(t--) {
        int n, m;
        std::cin >> n >> m;
        
        std::vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }
        
        if(possibleToReorder(n, m, arr)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
    
    return 0;
}