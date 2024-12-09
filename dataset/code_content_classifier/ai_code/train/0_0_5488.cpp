#include <iostream>
#include <algorithm>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    int num = std::min(a * d, b * c);
    int den = a * d + b * c;

    int common = gcd(num, den);

    std::cout << num / common << "/" << den / common << std::endl;

    return 0;
}