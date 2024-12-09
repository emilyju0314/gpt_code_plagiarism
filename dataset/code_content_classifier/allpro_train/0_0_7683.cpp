#include <iostream>
#include <string>

int main() {
    int K;
    std::string S;
    
    std::cin >> K;
    std::cin.ignore(); // Ignore newline
    
    std::getline(std::cin, S);
    
    if (S.length() <= K) {
        std::cout << S;
    } else {
        std::string result = S.substr(0, K) + "...";
        std::cout << result;
    }
    
    return 0;
}