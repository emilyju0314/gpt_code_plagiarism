#include <iostream>
#include <string>

bool isDivisibleBy64(std::string s) {
    int countZeros = 0;
    
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == '0') {
            countZeros++;
        } else {
            break;
        }
    }
    
    return countZeros >= 6;
}

int main() {
    std::string s;
    std::cin >> s;
    
    if (isDivisibleBy64(s)) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }
    
    return 0;
}