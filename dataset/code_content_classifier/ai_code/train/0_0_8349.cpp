#include <iostream>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int x, y, a, b;
    std::cin >> x >> y >> a >> b;

    int lcm = (x * y) / gcd(x, y);

    int count = 0;
    if (a % lcm == 0) {
        count = b / lcm - a / lcm + 1;
    } else {
        count = b / lcm - a / lcm;
    }

    std::cout << count << std::endl;

    return 0;
}