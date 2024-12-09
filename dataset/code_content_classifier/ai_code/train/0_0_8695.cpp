#include <iostream>
#include <string>

int main() {
    int k, a, b;
    std::string text;
    
    // Input
    std::cin >> k >> a >> b;
    std::cin >> text;
    
    // Check if solution is possible
    if (k * a > text.size() || k * b < text.size()) {
        std::cout << "No solution" << std::endl;
        return 0;
    }
    
    // Output lines
    int remaining = text.size();
    for (int i = 0; i < k; i++) {
        int len = remaining / (k - i) > b ? b : remaining / (k - i);
        std::cout << text.substr(text.size() - remaining, len) << std::endl;
        remaining -= len;
    }
    
    return 0;
}