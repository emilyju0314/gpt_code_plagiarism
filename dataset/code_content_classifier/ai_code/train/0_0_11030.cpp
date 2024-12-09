#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int t;
    std::string sequence;
    std::cin >> t >> sequence;

    int count = 0;
    int digits[10] = {0};

    for (char c : sequence) {
        digits[c - '0']++;
    }

    digits[6] = digits[9] = (digits[6] + digits[9] + 1) / 2;
    digits[2] = digits[5] = (digits[2] + digits[5] + 1) / 2;

    for (int i = 0; i <= 9; i++) {
        count = std::max(count, digits[i]);
    }

    std::cout << count << std::endl;

    return 0;
}