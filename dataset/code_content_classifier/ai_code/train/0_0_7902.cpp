#include <iostream>

long long factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int n;
    std::cin >> n;

    long long result = factorial(n / 2 - 1);
    result = result * factorial(n / 2 - 1);
    result = result / 2;

    std::cout << result << std::endl;

    return 0;
}