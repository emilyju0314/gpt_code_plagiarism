#include <iostream>
#include <string>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    if (n == 1 && k > 0) {
        std::cout << 0 << std::endl;
    } else {
        if (k > 0) {
            if (s[0] != '1') {
                s[0] = '1';
                k--;
            }
        }

        for (int i = 1; i < n && k > 0; i++) {
            if (s[i] != '0') {
                s[i] = '0';
                k--;
            }
        }

        std::cout << s << std::endl;
    }

    return 0;
}