#include <iostream>

int main() {
    int n;
    std::cin >> n;
    
    int min_val = 1000001;
    int max_val = -1000001;
    int sum = 0;
    
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        
        if (a < min_val) {
            min_val = a;
        }
        if (a > max_val) {
            max_val = a;
        }
        sum += a;
    }
    
    std::cout << min_val << " " << max_val << " " << sum << std::endl;
    
    return 0;
}