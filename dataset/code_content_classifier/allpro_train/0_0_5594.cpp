#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int a, b;
    a = 1;
    b = n;

    for (int i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            a = i;
            b = n / i;
        }
    }

    std::cout << a << " " << b << std::endl;

    return 0;
}