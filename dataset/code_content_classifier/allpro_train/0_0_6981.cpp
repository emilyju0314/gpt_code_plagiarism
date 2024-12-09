#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;

    std::unordered_map<char, bool> possibleLetters; // Map to store possible letters
    std::unordered_map<char, bool> electricShocks; // Map to store received electric shocks

    std::string action, word;
    char guess;

    for (int i = 0; i < n; ++i) {
        std::cin >> action >> word;

        if (action == "!") {
            char selectedLetter = word[0];
            electricShocks[selectedLetter] = true;

            for (auto it = possibleLetters.begin(); it != possibleLetters.end();) {
                if (it->first != selectedLetter) {
                    it = possibleLetters.erase(it);
                } else {
                    ++it;
                }
            }
        } else if (action == ".") {
            for (char c : word) {
                possibleLetters[c] = true;
            }
        } else {
            guess = word[0];
            if (possibleLetters.size() == 1 && possibleLetters.count(guess) != 0) {
                possibleLetters.clear();
                possibleLetters[guess] = true;
            }
        }
    }

    int excessiveShocks = 0;
    for (auto it = electricShocks.begin(); it != electricShocks.end(); ++it) {
        if (possibleLetters[it->first]) {
            ++excessiveShocks;
        }
    }

    std::cout << excessiveShocks << std::endl;

    return 0;
}