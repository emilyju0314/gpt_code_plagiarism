#include <iostream>
#include <unordered_set>

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        std::string s;
        std::cin >> s;

        std::unordered_set<char> workingButtons;
        std::unordered_set<char> malfunctioningButtons;

        char prevChar = s[0];
        workingButtons.insert(prevChar);

        for (int j = 1; j < s.size(); j++) {
            if (s[j] == prevChar) {
                workingButtons.erase(prevChar);
                malfunctioningButtons.insert(prevChar);
            } else {
                if (malfunctioningButtons.find(s[j]) == malfunctioningButtons.end()) {
                    workingButtons.insert(s[j]);
                }
            }

            prevChar = s[j];
        }

        for (char button : workingButtons) {
            std::cout << button;
        }
        std::cout << std::endl;
    }

    return 0;
}