#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s;
    std::cin >> s;
    
    int min_years = INT_MAX;
    
    for (int i = 1; i < s.length(); ++i) {
        int num1 = std::stoi(s.substr(0, i));
        int num2 = std::stoi(s.substr(i));
        
        min_years = std::min(min_years, abs(num1 - num2));
    }
    
    std::cout << min_years << std::endl;
    
    return 0;
}