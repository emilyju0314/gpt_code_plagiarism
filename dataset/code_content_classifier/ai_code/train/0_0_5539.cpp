#include <iostream>
#include <string>

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;

    int count = 1;
    for (int i = 2; i < s.length(); i += 2) {
        if (s[i] == s[0]) {
            count++;
        }
    }

    if (count == 1) {
        std::cout << 3 << std::endl;
    } else {
        std::cout << 2 * count + 1 << std::endl;
    }

    return 0;
}