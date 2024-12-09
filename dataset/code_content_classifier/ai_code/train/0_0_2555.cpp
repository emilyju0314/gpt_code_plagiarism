#include <iostream>
#include <string>

int main() {
    std::string s, t;
    std::cin >> s >> t;

    std::string p = s;
    bool possible = false;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] != t[i]) {
            p[i] = '0' + ('0' - s[i] + t[i]);
        } else {
            p[i] = s[i];
        }
    }

    for (int i = 0; i < s.length(); i++) {
        if (p[i] != s[i] && p[i] != t[i]) {
            possible = true;
            break;
        }
    }

    if (possible) {
        std::cout << p << std::endl;
    } else {
        std::cout << "impossible" << std::endl;
    }

    return 0;
}