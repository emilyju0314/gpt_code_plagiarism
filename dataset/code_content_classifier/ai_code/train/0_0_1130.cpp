#include <iostream>
#include <string>
#include <algorithm>

int countAOR(const std::string& s) {
    int count = 0;
    size_t pos = 0;
    while ((pos = s.find("AOR", pos)) != std::string::npos) {
        count++;
        pos += 3;
    }
    return count;
}

int main() {
    int N;
    std::cin >> N;
    
    int maxAOR = 0;
    for (int i = 0; i < N; i++) {
        std::string str;
        std::cin >> str;
        
        maxAOR += countAOR(str);
    }
    
    std::cout << maxAOR << std::endl;
    
    return 0;
}