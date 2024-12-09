#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s;
    std::cin >> s;

    int min_jump = 0;
    int current_jump = 0;

    for (char c : s) {
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y') {
            current_jump = 1;
        } else {
            current_jump++;
        }

        min_jump = std::max(min_jump, current_jump);
    }

    std::cout << min_jump << std::endl;

    return 0;
}