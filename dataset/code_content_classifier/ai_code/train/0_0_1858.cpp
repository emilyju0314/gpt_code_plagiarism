#include <iostream>
#include <cmath>

int main() {
    int a, b;
    std::cin >> a >> b;

    int max_len = 0;
    for (int base = 2; base <= 1000; base++) {
        int sum = a + b;
        int len = (int)log(sum) / log(base) + 1;
        max_len = std::max(max_len, len);
    }

    std::cout << max_len << std::endl;

    return 0;
}