#include <iostream>
#include <string>

int main() {
    int n, k;
    std::cin >> n >> k;

    if (n == 1 && k == 1) {
        std::cout << "a" << std::endl;
    } else if (n < k || k == 1) {
        std::cout << "-1" << std::endl;
    } else {
        std::string result = "";
        result += 'a';
        for (int i = 1; i < n - k + 1; i++) {
            result += (char)('a' + i);
        }
        for (int i = 0; i < k - 1; i++) {
            result += 'a';
        }
        std::cout << result << std::endl;
    }

    return 0;
}