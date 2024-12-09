#include <iostream>
#include <set>

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::set<char> distinctLetters;

    for (int i = 1; i < input.size() - 1; i++) {
        if (isalpha(input[i])) {
            distinctLetters.insert(input[i]);
        }
    }

    std::cout << distinctLetters.size() << std::endl;

    return 0;
}