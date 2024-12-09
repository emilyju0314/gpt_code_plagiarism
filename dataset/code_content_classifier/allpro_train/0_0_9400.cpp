#include <iostream>
#include <string>
#include <algorithm>

bool isEqual(std::string s1, std::string s2) {
    // Remove signs and ignore case
    s1.erase(std::remove_if(s1.begin(), s1.end(), [](char c){ return c == '-' || c == ';' || c == '_'; }), s1.end());
    s2.erase(std::remove_if(s2.begin(), s2.end(), [](char c){ return c == '-' || c == ';' || c == '_'; }), s2.end());
    
    // Convert to lowercase
    std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    
    return s1 == s2;
}

int main() {
    std::string first, second, third;
    std::cin >> first >> second >> third;
    
    int n;
    std::cin >> n;
    
    for (int i = 0; i < n; i++) {
        std::string answer;
        std::cin >> answer;
        
        if (isEqual(first + second + third, answer)) {
            std::cout << "ACC" << std::endl;
        } else {
            std::cout << "WA" << std::endl;
        }
    }
    
    return 0;
}