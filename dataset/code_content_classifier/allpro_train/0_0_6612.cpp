#include <iostream>
#include <cmath>

int main() {
    int x, y, n;
    std::cin >> x >> y >> n;
    
    int a = floor((double)x * n / y);
    int b = n;
    
    long long min_diff = INT_MAX; // Initialize minimum difference to a large value
    
    for (int i = n; i >= 1; i--) {
        int j = floor(((double)x * i) / y);
        if (abs(x * i - j * y) < min_diff) {
            a = j;
            b = i;
            min_diff = abs(x * i - j * y);
        } else if (abs(x * i - j * y) == min_diff && i < b) {
            a = j;
            b = i;
        }
    }
    
    std::cout << a << "/" << b << std::endl;
    
    return 0;
}