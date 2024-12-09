#include <iostream>
#include <vector>
#include <string>
#include <sstream>

bool isValidVersePattern(int n, std::vector<int>& versePattern, std::vector<std::string>& text) {
    for (int i = 0; i < n; i++) {
        std::istringstream iss(text[i]);
        std::string word;
        int syllableCount = 0;
        while (iss >> word) {
            int vowelCount = 0;
            for (char c : word) {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
                    vowelCount++;
                }
            }
            if (vowelCount >= 1) {
                syllableCount += vowelCount;
            }
        }
        if (syllableCount != versePattern[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> versePattern(n);
    for (int i = 0; i < n; i++) {
        std::cin >> versePattern[i];
    }
    
    std::cin.ignore();
    
    std::vector<std::string> text(n);
    for (int i = 0; i < n; i++) {
        std::getline(std::cin, text[i]);
    }
    
    if (isValidVersePattern(n, versePattern, text)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    
    return 0;
}