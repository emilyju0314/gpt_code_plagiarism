#include <iostream>
#include <string>

bool canTransform(std::string s, std::string t) {
    if(s.length() != t.length()) {
        return false;
    }

    for(int i = 0; i < s.length(); i++) {
        if((s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') &&
           (t[i] == 'a' || t[i] == 'e' || t[i] == 'i' || t[i] == 'o' || t[i] == 'u')) {
            continue;
        } else if((s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u') &&
                  (t[i] != 'a' && t[i] != 'e' && t[i] != 'i' && t[i] != 'o' && t[i] != 'u')) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    std::string s, t;
    std::cin >> s >> t;

    if(canTransform(s, t)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}