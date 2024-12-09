#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;

    int total = a + b;
    int alice_share = total / 2;

    std::cout << alice_share << std::endl;

    return 0;
}