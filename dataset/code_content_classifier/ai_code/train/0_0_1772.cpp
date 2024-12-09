#include <iostream>
#include <cmath>

int main() {
    long long a;
    std::cin >> a;

    int b = 1;
    while (true) {
        if (std::to_string(std::abs(a + b)).find('8') != std::string::npos) {
            break;
        }
        b++;
    }

    std::cout << b << std::endl;

    return 0;
}