#include <iostream>
#include <string>
#include <vector>

bool containsSubstring(const std::string& password, const std::vector<std::string>& words) {
    for (const std::string& word : words) {
        if (word.find(password) != std::string::npos) {
            return true;
        }
    }
    return false;
}

int main() {
    std::string password;
    std::cin >> password;

    int n;
    std::cin >> n;

    std::vector<std::string> words(n);
    for (int i = 0; i < n; i++) {
        std::cin >> words[i];
    }

    if (containsSubstring(password, words)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}