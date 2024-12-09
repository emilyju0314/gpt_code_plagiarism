#include <iostream>
#include <string>

bool is_palindrome(const std::string& s) {
    for (int i = 0; i < s.length() / 2; i++) {
        if (s[i] != s[s.length() - i - 1]) {
            return false;
        }
    }
    return true;
}

int min_cuts(const std::string& s) {
    if (is_palindrome(s)) {
        return s.length() == 1 ? 0 : 1;
    } else {
        for (int i = 1; i < s.length(); i++) {
            std::string left = s.substr(0, i);
            std::string right = s.substr(i);
            std::string new_string = right + left;
            if (is_palindrome(new_string) && new_string != s) {
                return 1;
            }
        }
    }
    return 2;
}

int main() {
    std::string s;
    std::cin >> s;

    int ans = min_cuts(s);
    if (ans == 2 && s.length() % 2 == 0) {
        std::cout << "Impossible" << std::endl;
    } else {
        std::cout << ans << std::endl;
    }

    return 0;
}