#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    int num_pairs = 0;
    int length = s.length();

    for (int i = 0; i < length; i++) {
        for (int j = i + 3; j < length; j++) {
            if (s.substr(i, j - i + 1).find("bear") != std::string::npos) {
                num_pairs++;
            }
        }
    }

    std::cout << num_pairs << std::endl;

    return 0;
}