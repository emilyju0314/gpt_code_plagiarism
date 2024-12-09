#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    std::string pattern;
    std::cin >> n >> pattern;

    std::vector<std::string> possible_names = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

    for (const std::string& name : possible_names) {
        if (name.size() == n) {
            bool match = true;
            for (int i = 0; i < n; i++) {
                if (pattern[i] != '.' && pattern[i] != name[i]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                std::cout << name << std::endl;
                break;
            }
        }
    }

    return 0;
}