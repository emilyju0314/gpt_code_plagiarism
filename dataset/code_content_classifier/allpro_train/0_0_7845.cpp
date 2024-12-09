#include <iostream>
#include <string>
#include <vector>

bool isHaikuPhrase(const std::string& phrase, int syllables) {
    int count = 0;
    for (char c : phrase) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    return count == syllables;
}

int main() {
    std::string phrase1, phrase2, phrase3;

    std::getline(std::cin >> std::ws, phrase1);
    std::getline(std::cin >> std::ws, phrase2);
    std::getline(std::cin >> std::ws, phrase3);

    if (isHaikuPhrase(phrase1, 5) && isHaikuPhrase(phrase2, 7) && isHaikuPhrase(phrase3, 5)) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }

    return 0;
}