#include <iostream>

int main() {
    long long a, b;
    std::cin >> a >> b;

    while (a != 0 && b != 0) {
        if (a >= 2 * b) {
            a -= 2 * b;
        } else if (b >= 2 * a) {
            b -= 2 * a;
        } else {
            break;
        }
    }

    std::cout << a << " " << b << std::endl;

    return 0;
}