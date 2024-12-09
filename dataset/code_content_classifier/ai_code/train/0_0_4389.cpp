#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool isSimilar(const std::string& s, const std::string& t) {
    if (s.size() != t.size()) {
        return false;
    }

    for (int i = 0; i < s.size(); i++) {
        if (s[i] != t[i]) {
            if (std::tolower(s[i]) != std::tolower(t[i])) {
                return false;
            }

            if ((s[i] == '0' && t[i] != 'O') || (s[i] == 'O' && t[i] != '0') ||
                (s[i] == '1' && t[i] != 'l' && t[i] != 'I') || (t[i] == '1' && s[i] != 'l' && s[i] != 'I')) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    std::string newUser;
    std::cin >> newUser;

    int n;
    std::cin >> n;

    std::vector<std::string> existingLogins(n);
    for (int i = 0; i < n; i++) {
        std::cin >> existingLogins[i];
    }

    bool isUnique = true;
    for (const auto& login : existingLogins) {
        if (isSimilar(newUser, login)) {
            isUnique = false;
            break;
        }
    }

    if (isUnique) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}