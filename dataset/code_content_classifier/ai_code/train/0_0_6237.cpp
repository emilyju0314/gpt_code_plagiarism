#include <iostream>
#include <string>

bool is_palindrome(const std::string& s) {
    int left = 0;
    int right = s.length() - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

bool is_reorderable(const std::string& s, int cut_pos) {
    std::string reordered = s.substr(cut_pos) + s.substr(0, cut_pos);
    return reordered != s;
}

int main() {
    std::string s;
    std::cin >> s;

    if (is_palindrome(s)) {
        for (int i = 1; i < s.length(); i++) {
            if (is_reorderable(s, i)) {
                std::cout << "1" << std::endl;
                return 0;
            }
        }
        std::cout << "Impossible" << std::endl;
    } else {
        std::cout << "0" << std::endl;
    }

    return 0;
}