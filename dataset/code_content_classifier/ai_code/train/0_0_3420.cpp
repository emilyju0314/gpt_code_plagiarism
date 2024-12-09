#include <iostream>
#include <string>
#include <vector>

bool isNumber(std::string word) {
    if (word.empty() || (word.length() > 1 && word[0] == '0') || !std::all_of(word.begin(), word.end(), ::isdigit)) {
        return false;
    } else {
        return true;
    }
}

int main() {
    std::string s;
    std::getline(std::cin, s);

    std::vector<std::string> numbers;
    std::vector<std::string> nonNumbers;

    std::string word;
    for (char c : s) {
        if (c == ',' || c == ';') {
            if (!word.empty()) {
                if (isNumber(word)) {
                    numbers.push_back(word);
                } else {
                    nonNumbers.push_back(word);
                }
            }
            word = "";
        } else {
            word += c;
        }
    }

    if (!word.empty()) {
        if (isNumber(word)) {
            numbers.push_back(word);
        } else {
            nonNumbers.push_back(word);
        }
    }

    if (numbers.empty()) {
        std::cout << "-";
    } else {
        std::cout << "\"";
        for (int i = 0; i < numbers.size()-1; i++) {
            std::cout << numbers[i] << ",";
        }
        std::cout << numbers[numbers.size()-1] << "\"";
    }

    std::cout << std::endl;

    if (nonNumbers.empty()) {
        std::cout << "-";
    } else {
        std::cout << "\"";
        for (int i = 0; i < nonNumbers.size()-1; i++) {
            std::cout << nonNumbers[i] << ",";
        }
        std::cout << nonNumbers[nonNumbers.size()-1] << "\"";
    }

    return 0;
}