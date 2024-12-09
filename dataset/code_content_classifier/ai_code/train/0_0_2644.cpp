#include <iostream>

int main() {
    int n, b, p;
    std::cin >> n >> b >> p;

    int bottles = n * b;
    int towels = n * p;

    while (n > 1) {
        int k = 1;
        while (2 * k <= n) k *= 2;

        int matches = n - k;
        bottles += matches * b;
        towels += matches * p;

        n = k;
    }

    std::cout << bottles << " " << towels << std::endl;

    return 0;
}