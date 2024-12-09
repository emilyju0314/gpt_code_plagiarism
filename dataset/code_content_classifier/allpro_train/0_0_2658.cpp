#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    bool possible = false;

    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '?' || s[i + 1] == '?' || s[i] != s[i + 1]) {
            possible = true;
            break;
        }
    }

    if (possible) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}