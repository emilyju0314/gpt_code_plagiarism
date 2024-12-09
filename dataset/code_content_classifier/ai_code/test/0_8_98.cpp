#include <iostream>
#include <string>
#include <cmath>

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        std::string keyboard, word;
        std::cin >> keyboard >> word;

        int time = 0;
        int current_pos = 0;

        for(int j = 0; j < word.length(); j++) {
            int letter_pos = keyboard.find(word[j]);
            time += std::abs(letter_pos - current_pos);
            current_pos = letter_pos;
        }

        std::cout << time << std::endl;
    }

    return 0;
}