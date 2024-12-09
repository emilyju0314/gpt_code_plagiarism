#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::string s;
        std::cin >> s;

        if (s.find("NN") != std::string::npos && s.find("E") != std::string::npos) {
            std::cout << "NO" << std::endl;
        } else {
            std::cout << "YES" << std::endl;
        }
    }

    return 0;
}