#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::string prev;
    std::cin >> prev;

    int groups = 1;

    for (int i = 1; i < n; i++) {
        std::string s;
        std::cin >> s;

        if (s != prev) {
            groups++;
            prev = s;
        }
    }

    std::cout << groups << std::endl;

    return 0;
}