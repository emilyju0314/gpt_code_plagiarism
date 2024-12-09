#include <iostream>
#include <string>
#include <cmath>

int main() {
    std::string s;
    std::cin >> s;

    int min_diff = 1000;
    for (int i = 0; i < s.size() - 2; i++) {
        int x = std::stoi(s.substr(i, 3));
        int diff = std::abs(x - 753);
        if (diff < min_diff) {
            min_diff = diff;
        }
    }

    std::cout << min_diff << std::endl;

    return 0;
}