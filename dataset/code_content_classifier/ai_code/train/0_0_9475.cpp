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
    
    std::sort(arr.begin(), arr.end());
    
    int max_freq = 1;
    int curr_freq = 1;
    for(int i = 1; i < n; i++) {
        if(arr[i] == arr[i-1]) {
            curr_freq++;
            max_freq = std::max(max_freq, curr_freq);
        } else {
            curr_freq = 1;
        }
    }
    
    if(max_freq <= (n+1)/2) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    
    return 0;
}