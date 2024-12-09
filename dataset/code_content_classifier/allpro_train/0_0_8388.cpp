#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::string word;
    std::vector<std::string> words;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ' ' || input[i] == '.' || input[i] == ',') {
            if (word.length() >= 3 && word.length() <= 6) {
                words.push_back(word);
            }
            word = "";
        } else {
            word += input[i];
        }
    }

    if (word.length() >= 3 && word.length() <= 6) {
        words.push_back(word);
    }

    for (int i = 0; i < words.size(); i++) {
        std::cout << words[i];
        if (i < words.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}