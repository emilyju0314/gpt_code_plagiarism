#include <iostream>
#include <vector>

void rotate90(std::vector<std::string>& pattern) {
    std::vector<std::string> rotated(8, "********");
    
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            rotated[j][7-i] = pattern[i][j];
        }
    }
    
    pattern = rotated;
}

void rotate180(std::vector<std::string>& pattern) {
    rotate90(pattern);
    rotate90(pattern);
}

void rotate270(std::vector<std::string>& pattern) {
    rotate180(pattern);
    rotate90(pattern);
}

int main() {
    std::vector<std::string> pattern(8);
    
    for(int i = 0; i < 8; i++) {
        std::cin >> pattern[i];
    }
    
    std::cout << "90" << std::endl;
    rotate90(pattern);
    for(int i = 0; i < 8; i++) {
        std::cout << pattern[i] << std::endl;
    }
    
    std::cout << "180" << std::endl;
    rotate180(pattern);
    for(int i = 0; i < 8; i++) {
        std::cout << pattern[i] << std::endl;
    }
    
    std::cout << "270" << std::endl;
    rotate270(pattern);
    for(int i = 0; i < 8; i++) {
        std::cout << pattern[i] << std::endl;
    }
    
    return 0;
}