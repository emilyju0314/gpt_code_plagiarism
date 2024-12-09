#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;
    
    for(int i = 0; i < t; i++) {
        std::string s;
        std::cin >> s;
        
        bool isSquare = true;
        int n = s.length();
        
        if(n % 2 != 0) {
            isSquare = false;
        } else {
            for(int j = 0; j < n/2; j++) {
                if(s[j] != s[j + n/2]) {
                    isSquare = false;
                    break;
                }
            }
        }
        
        if(isSquare) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
    
    return 0;
}