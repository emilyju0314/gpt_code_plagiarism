#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::string number;
    std::cin >> number;

    // Shuffle the digits
    std::vector<char> digits(number.begin(), number.end());
    std::swap(digits[1], digits[2]);
    std::swap(digits[3], digits[4]);

    // Raise the number to the fifth power
    std::string result;
    for (int i = 0; i < 5; i++) {
        result += std::to_string((digits[0] - '0') * (digits[1] - '0') * (digits[2] - '0') *
                                 (digits[3] - '0') * (digits[4] - '0'));
    }

    // Output the last 5 digits
    std::cout << result.substr(result.size() - 5) << std::endl;

    return 0;
}