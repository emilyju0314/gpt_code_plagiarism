#include <iostream>
#include <cmath>

int main() {
    int n;
    
    while (std::cin >> n) {
        if (n == 0) {
            break;
        }
        
        long long ans = 6 * n;
        
        for (int i = 2; i*i <= n; ++i) {
            if (n % i == 0) {
                int count = 0;
                
                while (n % i == 0) {
                    n /= i;
                    ++count;
                }
                
                ans *= 2*count + 1;
            }
        }
        
        if (n > 1) {
            ans *= 3;
        }
        
        std::cout << ans << std::endl;
    }
    
    return 0;
}