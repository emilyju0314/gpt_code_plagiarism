#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    int n = s.length();

    for (int i = 0; i < n - 1; i++) {
        int count = 1;
        char current = s[i];
        for (int j = i + 1; j < n; j++) {
            if (s[j] == current) {
                count++;
            }
            if (count > n / 2) {
                std::cout << i + 1 << " " << j + 1 << std::endl;
                return 0;
            }
        }
    }

    std::cout << "-1 -1" << std::endl;

    return 0;
}