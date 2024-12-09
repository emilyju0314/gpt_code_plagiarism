#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    int cf_count = 0;
    for (char c : s) {
        if (c == 'C' || c == 'F') {
            cf_count++;
        }
    }

    if (cf_count >= 2) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}