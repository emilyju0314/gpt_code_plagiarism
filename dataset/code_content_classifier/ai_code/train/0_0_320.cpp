#include <iostream>
#include <string>
#include <unordered_map>

int minimum_partitions_for_palindrome(std::string s) {
    std::unordered_map<char, int> char_count;
    int odd_count = 0;

    for (char c : s) {
        char_count[c]++;
    }

    for (auto it = char_count.begin(); it != char_count.end(); it++) {
        if (it->second % 2 != 0) {
            odd_count++;
        }
    }

    return (odd_count == 0) ? 1 : odd_count;
}

int main() {
    std::string s;
    std::cin >> s;

    int result = minimum_partitions_for_palindrome(s);
    std::cout << result << std::endl;

    return 0;
}