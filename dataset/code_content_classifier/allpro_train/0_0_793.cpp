#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string n, m;
    std::cin >> n >> m;

    std::sort(n.begin(), n.end());

    if (n[0] == '0') {
        for (int i = 1; i < n.size(); i++) {
            if (n[i] != '0') {
                std::swap(n[0], n[i]);
                break;
            }
        }
    }

    if (n == m) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "WRONG_ANSWER" << std::endl;
    }

    return 0;
}