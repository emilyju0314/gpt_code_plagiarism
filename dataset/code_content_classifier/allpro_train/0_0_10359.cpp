#include <iostream>
#include <string>
#include <unordered_set>

int calculateSum(std::string num) {
    std::unordered_set<char> digits;
    for (char c : num) {
        if (isdigit(c)) {
            digits.insert(c);
        } else {
            digits.insert(c - 'a' + 10);
        }
    }

    int sum = 0;
    for (char c : digits) {
        sum += 1 << (c - '0');
    }

    return sum;
}

int main() {
    int q;
    std::cin >> q;

    while (q--) {
        std::string l, r;
        std::cin >> l >> r;

        int count = 0;
        for (int i = std::stoi(l, 0, 16); i <= std::stoi(r, 0, 16); i++) {
            std::string num = std::to_string(i);
            int sum = calculateSum(num);

            int xor_result = i ^ sum;
            if (xor_result < i) {
                count++;
            }
        }

        std::cout << count << std::endl;
    }

    return 0;
}