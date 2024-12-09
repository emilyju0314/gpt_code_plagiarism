#include <iostream>
#include <string>

bool isSquare(std::string s) {
    int n = s.length();
    if (n % 2 != 0) {
        return false;
    }
    
    for (int i = 0; i < n/2; i++) {
        if (s[i] != s[i + n/2]) {
            return false;
        }
    }
    
    return true;
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