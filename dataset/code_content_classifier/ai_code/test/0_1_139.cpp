#include <iostream>
#include <string>

bool isSquare(const std::string& s) {
    int n = s.length();
    if (n % 2 != 0) {
        return false;
    }
    
    std::string first_half = s.substr(0, n/2);
    std::string second_half = s.substr(n/2, n/2);
    
    return first_half == second_half;
}

int main() {
    int t;
    std::cin >> t;
    
    while (t--) {
        std::string s;
        std::cin >> s;
        
        if (isSquare(s)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
    
    return 0;
}