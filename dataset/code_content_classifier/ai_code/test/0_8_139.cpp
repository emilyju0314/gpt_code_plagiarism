#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;
    
    for(int i = 0; i < t; i++) {
        std::string s;
        std::cin >> s;
        
        bool isSquare = false;
        
        if(s.length() % 2 == 0) {
            std::string firstHalf = s.substr(0, s.length() / 2);
            std::string secondHalf = s.substr(s.length() / 2, s.length() / 2);
            
            if(firstHalf == secondHalf) {
                isSquare = true;
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