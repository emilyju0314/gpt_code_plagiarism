#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::string s;
        std::cin >> s;

        // Check if the first character and the last character are consistent
        if (s.front() == 'E' && s.back() == 'N') {
            std::cout << "NO" << std::endl;
            continue;
        }

        // Check if the characters in the string are consistent
        bool consistent = true;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == 'N' && s[i-1] == 'N') {
                consistent = false;
                break;
            }
        }

        if (consistent) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}