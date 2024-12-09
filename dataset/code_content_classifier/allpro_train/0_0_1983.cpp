#include <iostream>
#include <string>
#include <vector>

bool is_match(const std::string& pattern, const std::string& word) {
    if (pattern.size() == 0) {
        return word.size() == 0;
    }

    char first = pattern[0];
    if (first == '(') {
        int open_count = 1;
        int close_count = 0;
        int i = 1;
        while (open_count != close_count) {
            if (pattern[i] == '(') {
                open_count++;
            } else if (pattern[i] == ')') {
                close_count++;
            }
            i++;
        }
        std::string inner_pattern = pattern.substr(1, i - 2);
        return is_match(inner_pattern, word);
    } else if (first == '.') {
        if (word.size() == 0) {
            return false;
        }
        return is_match(pattern.substr(1), word.substr(1));
    } else if (first == '^') {
        return is_match(pattern.substr(1), word);
    } else if (first == '|') {
        return is_match(pattern.substr(1), word) || is_match(pattern.substr(pattern.find('|') + 1), word);
    } else if (first == '*') {
        return is_match(pattern.substr(1), word) || (word.size() > 0 && is_match(pattern, word.substr(1)));
    } else {
        if (first == word[0]) {
            return is_match(pattern.substr(1), word.substr(1));
        } else {
            return false;
        }
    }
}

int main() {
    int h, w;
    while (true) {
        std::cin >> h >> w;
        if (h == 0 && w == 0) {
            break;
        }

        std::vector<std::string> across_clues(h), down_clues(w);

        for (int i = 0; i < h; i++) {
            std::cin >> across_clues[i];
        }

        for (int i = 0; i < w; i++) {
            std::cin >> down_clues[i];
        }

        bool found_solution = false;
        std::string solution;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                std::string word = "A";
                if (is_match(across_clues[i], word) && is_match(down_clues[j], word)) {
                    if (found_solution) {
                        // Multiple solutions found
                        found_solution = false;
                        break;
                    } else {
                        found_solution = true;
                        solution += word + "\n";
                    }
                }
            }
        }

        if (found_solution) {
            std::cout << solution;
        } else {
            if (solution.size() == 0) {
                std::cout << "none" << std::endl;
            } else {
                std::cout << "ambiguous" << std::endl;
            }
        }
    }

    return 0;
}