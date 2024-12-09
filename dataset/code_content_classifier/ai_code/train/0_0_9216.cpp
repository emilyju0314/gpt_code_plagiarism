#include <iostream>
#include <cmath>

int main() {
    int a;
    std::cin >> a;

    int result = std::ceil(log2(a));

    std::cout << result << std::endl;

    return 0;
}