#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> lines;
    std::string line;
    
    // Read input lines
    while (std::getline(std::cin, line)) {
        lines.push_back(line);
    }
    
    // Find the maximum line length
    int max_length = 0;
    for (const std::string& l : lines) {
        max_length = std::max(max_length, (int)l.length());
    }
    
    // Output the aligned text
    std::cout << std::string(max_length + 2, '*') << std::endl;
    for (const std::string& l : lines) {
        int padding = max_length - l.length();
        int left = padding / 2;
        int right = padding - left;
        
        std::cout << '*';
        std::cout << std::string(left, ' ');
        std::cout << l;
        std::cout << std::string(right, ' ');
        std::cout << '*' << std::endl;
    }
    std::cout << std::string(max_length + 2, '*') << std::endl;
    
    return 0;
}