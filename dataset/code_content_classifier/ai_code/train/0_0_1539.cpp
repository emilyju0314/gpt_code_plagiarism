#include <iostream>
#include <string>

int main() {
    std::string S;
    std::cin >> S;
    
    bool isHardToEnter = false;
    for (int i = 0; i < 3; i++) {
        if (S[i] == S[i+1]) {
            isHardToEnter = true;
            break;
        }
    }
    
    if (isHardToEnter) {
        std::cout << "Bad" << std::endl;
    } else {
        std::cout << "Good" << std::endl;
    }
    
    return 0;
}