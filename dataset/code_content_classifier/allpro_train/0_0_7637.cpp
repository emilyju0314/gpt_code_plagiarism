#include <iostream>
#include <vector>
#include <algorithm>

int minReplacement(std::vector<int>& a, int n, int k) {
    int left = 0, right = 0;
    int ans = 0;
    
    while(left <= right) {
        if(a[left] != a[right]) {
            ans++;
            if(a[left] > a[right]) {
                a[right] = a[left];
            } else {
                a[left] = a[right];
            }
        }
        left++;
        right--;
    }
    
    return ans;
}

int main() {
    int t;
    std::cin >> t;
    
    for(int i = 0; i < t; i++) {
        int n, k;
        std::cin >> n >> k;
        
        std::vector<int> a(n);
        for(int j = 0; j < n; j++) {
            std::cin >> a[j];
        }
        
        int result = minReplacement(a, n, k);
        std::cout << result << std::endl;
    }
    
    return 0;
}