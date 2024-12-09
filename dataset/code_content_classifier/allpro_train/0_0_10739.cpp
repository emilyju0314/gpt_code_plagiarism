#include <iostream>
#include <string>
#include <cctype>

int main() {
    int counts[26] = {0};
    std::string sentence;

    while (std::getline(std::cin, sentence)) {
        for (char c : sentence) {
            if (std::isalpha(c)) {
                counts[std::tolower(c) - 'a']++;
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        std::cout << static_cast<char>('a' + i) << " : " << counts[i] << std::endl;
    }

    return 0;
}