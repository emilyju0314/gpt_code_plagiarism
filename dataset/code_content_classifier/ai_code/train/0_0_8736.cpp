#include <iostream>
#include <string>
#include <vector>

bool isSafe(const std::string& s) {
    std::vector<int> locks(10, 0);

    for (char c : s) {
        if (c == 'u') {
            for (int i = 0; i < 10; i++) {
                locks[i] = 0;
            }
        } else {
            int lock = c - '0';
            if (locks[lock] == 1) {
                return false;
            } else {
                locks[lock] = 1;
            }
        }
    }

    return true;
}

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::string s;
        std::cin >> s;

        if (isSafe(s)) {
            std::cout << "SAFE" << std::endl;
        } else {
            std::cout << "UNSAFE" << std::endl;
        }
    }

    return 0;
}