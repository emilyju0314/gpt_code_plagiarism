#include <iostream>
#include <sstream>
#include <unordered_map>

int main() {
    std::string text;
    std::getline(std::cin, text);

    std::istringstream iss(text);
    std::string word;
    std::unordered_map<std::string, int> frequency;
    std::string most_frequent_word;
    int max_frequency = 0;

    std::string longest_word;
    int max_length = 0;

    while (iss >> word) {
        frequency[word]++;
        if (frequency[word] > max_frequency) {
            max_frequency = frequency[word];
            most_frequent_word = word;
        }

        if (word.length() > max_length) {
            max_length = word.length();
            longest_word = word;
        }
    }

    std::cout << most_frequent_word << " " << longest_word << std::endl;

    return 0;
}