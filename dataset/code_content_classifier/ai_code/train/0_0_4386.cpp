#include <iostream>
#include <string>

bool isConsonant(char c) {
    return (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u');
}

int main() {
    std::string word;
    std::cin >> word;

    std::string result = "";
    int consecutiveConsonants = 0;
    char lastConsonant = '\0';

    for (char c : word) {
        if (isConsonant(c)) {
            if (consecutiveConsonants < 2 || c != lastConsonant) {
                consecutiveConsonants++;
                if (consecutiveConsonants >= 3) {
                    result += ' ';
                    consecutiveConsonants = 1;
                }
            }
            lastConsonant = c;
        } else {
            consecutiveConsonants = 0;
            lastConsonant = '\0';
        }
        result += c;
    }

    std::cout << result << std::endl;

    return 0;
}