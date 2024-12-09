#include <iostream>
#include <string>

int main() {
    std::string s, t;
    std::cin >> s >> t;
    
    std::string reversed_s = s;
    std::reverse(reversed_s.begin(), reversed_s.end());
    
    if (reversed_s == t) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    
    return 0;
}