#include <iostream>
#include <unordered_set>

int main() {
    int N;
    std::cin >> N;

    std::unordered_set<std::string> words;
    std::string prev_word;
    bool valid = true;

    for (int i = 0; i < N; i++) {
        std::string current_word;
        std::cin >> current_word;

        if (i != 0 && current_word.front() != prev_word.back()) {
            valid = false;
            break;
        }

        if (words.find(current_word) != words.end()) {
            valid = false;
            break;
        }

        words.insert(current_word);
        prev_word = current_word;
    }

    if (valid) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}