#include <iostream>
#include <string>

bool canConstructSubstring(std::string S, std::string T, int k) {
    std::string concatStr;
    for (int i = 0; i <= T.length() - k; i++) {
        std::string substr = T.substr(i, k);
        concatStr += substr;
        if (concatStr == S) {
            return true;
        }
    }
    return false;
}

int main() {
    std::string S, T;
    int k;
    
    std::cin >> S >> T >> k;
    
    if (canConstructSubstring(S, T, k)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    
    return 0;
}