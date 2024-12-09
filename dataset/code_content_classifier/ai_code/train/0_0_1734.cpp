#include <iostream>

int main() {
    long long n;
    std::cin >> n;

    long long a = 1, b = 1;

    while (true) {
        std::cout << a << " " << b << std::endl;
        std::cout.flush();

        int ans;
        std::cin >> ans;

        if (ans == 0) {
            break;
        } else if (ans == 1) {
            a++;
        } else if (ans == 2) {
            b++;
        } else if (ans == 3) {
            a++;
            b++;
        }

        if (a > n) a = 1;
        if (b > n) b = 1;
    }

    return 0;
}