#include <iostream>
#include <string>
#include <vector>

int countInadequateNumbers(const std::string& s) {
    std::vector<int> inadequate_numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int count = 0;

    for (int i = 0; i < s.length(); i++) {
        int num = 0;
        for (int j = i; j < s.length(); j++) {
            num = num * 10 + (s[j] - '0');

            if (num >= 10) {
                int k = inadequate_numbers.size();
                int last_digit = inadequate_numbers[(num / 10) % k];
                if (num % 10 < last_digit) {
                    count++;
                }
            } else if (std::find(inadequate_numbers.begin(), inadequate_numbers.end(), num) != inadequate_numbers.end()) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    std::string s;
    std::cin >> s;

    int result = countInadequateNumbers(s);
    std::cout << result << std::endl;

    return 0;
}