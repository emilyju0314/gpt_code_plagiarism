#include <iostream>
#include <string>
#include <vector>

int main() {
    int n, q;
    std::string x;
    
    // Input n, x, q
    std::cin >> n;
    std::cin >> x;
    std::cin >> q;
    
    // Initialize variables to store sum and product
    int sum = 0, product = 0;
    
    // Calculate initial sum and product
    for(int i = 0; i < n; i++) {
        sum += x[i] - '0';
        if(i < n-1) {
            product += (x[i] - '0') * (x[i+1] - '0');
        }
    }
    
    // Perform q operations
    for(int i = 0; i < q; i++) {
        int l, r, b;
        std::cin >> l >> r >> b;
        
        // Update sum and product based on the operation
        for(int j = l-1; j <= r-1; j++) {
            sum -= (x[j] - '0');
            product -= (j < n-1) ? (x[j] - '0') * (x[j+1] - '0') : 0;
            x[j] = b + '0';
            sum += (x[j] - '0');
            product += (j < n-1) ? (x[j] - '0') * (x[j+1] - '0') : 0;
        }
        
        // Output f(x) - g(x)
        std::cout << sum - product << std::endl;
    }
    
    return 0;
}