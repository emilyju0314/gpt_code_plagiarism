#include <iostream>
#include <vector>
#include <sstream>

int main() {
    int a, b, c, N;
    
    while (true) {
        std::cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) {
            break;
        }
        std::cin >> N;
        
        std::vector<int> parts(a + b + c + 1, 2); // Initialize all parts as not decided
        
        int i, j, k, r;
        while (N--) {
            std::cin >> i >> j >> k >> r;
            if (r == 0) { // If the test failed
                parts[i] = parts[j] = parts[k] = 0; // Mark all parts used in the test as faulty
            } else {
                if (parts[i] != 0 && parts[j] != 0 && parts[k] != 0) { // If the test passed and parts are not marked as faulty
                    parts[i] = parts[j] = parts[k] = 1; // Mark all parts as normal
                }
            }
        }
        
        for (int idx = 1; idx <= a + b + c; idx++) {
            std::cout << parts[idx] << std::endl; // Output the classification result for each part
        }
    }
    
    return 0;
}