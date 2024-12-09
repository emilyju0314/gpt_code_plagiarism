#include <iostream>
#include <string>

bool isMirrorWord(const std::string& word) {
    std::string mirror = "AHIMOTUVWXY";
    
    for (int i = 0; i < word.length(); i++) {
        if (word[i] != mirror[mirror.length() - 1 - i]) {
            return false;
        }
    }
    
    return true;
}

int main() {
    std::string word;
    std::cin >> word;
    
    if (isMirrorWord(word)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    
    return 0;
}