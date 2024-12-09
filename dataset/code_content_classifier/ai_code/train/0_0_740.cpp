#include <iostream>

int main() {
    int n, m, z;
    std::cin >> n >> m >> z;

    int lcm = (n * m) / __gcd(n, m);

    int result = z / lcm;
    std::cout << result << std::endl;

    return 0;
}