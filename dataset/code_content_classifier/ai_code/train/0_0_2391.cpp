#include <iostream>
#include <string>

std::string abbreviateWord(std::string word) {
    if (word.length() > 10) {
        return word[0] + std::to_string(word.length() - 2) + word[word.length() - 1];
    } else {
        return word;
    }
}

int main() {
    int n;
    std::cin >> n;
    
    for (int i = 0; i < n; i++) {
        std::string word;
        std::cin >> word;
        std::cout << abbreviateWord(word) << std::endl;
    }
    
    return 0;
}