#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;
    
    while(t--) {
        int n, k;
        std::cin >> n >> k;
        
        std::vector<int> a(n);
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        
        std::sort(a.begin(), a.end());
        
        int score = 0;
        for(int i = 0; i < k; i++) {
            score += a[i];
        }
        
        std::cout << score << std::endl;
    }
    
    return 0;
}