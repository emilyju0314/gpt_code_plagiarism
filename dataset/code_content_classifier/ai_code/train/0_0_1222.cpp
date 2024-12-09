#include <iostream>
#include <string>

bool isBerlanese(std::string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' && s[i] != 'n') {
            if (i == s.length() - 1) {
                return false;
            } else if (s[i + 1] != 'a' && s[i + 1] != 'e' && s[i + 1] != 'i' && s[i + 1] != 'o' && s[i + 1] != 'u') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::string s;
    std::cin >> s;

    if (isBerlanese(s)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}