#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;
    
    for(int i=0; i<t; i++) {
        std::string s;
        std::cin >> s;
        
        bool square = false;
        int n = s.length();
        
        if(n % 2 == 0) {
            std::string first = s.substr(0, n/2);
            std::string second = s.substr(n/2, n/2);
            if(first == second) {
                square = true;
            }
        }
        
        if(square) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
    
    return 0;
}