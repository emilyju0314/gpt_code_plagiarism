#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    
    while(t--) {
        int n;
        long long k;
        std::cin >> n >> k;
        
        std::vector<int> a(n);
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        
        long long sum = 0;
        int minSteps = 0;
        for(int i = 0; i < n; i++) {
            sum += a[i];
            if(sum > k) {
                minSteps += (sum - k);
                sum = k;
            }
        }
        
        std::cout << minSteps << std::endl;
    }
    
    return 0;
}