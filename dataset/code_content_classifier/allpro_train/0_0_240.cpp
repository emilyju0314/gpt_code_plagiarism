#include <iostream>
#include <cmath>

double area(int a, int l, int x) {
    double s1 = (a + l + l + x) / 2.0;
    double s2 = (a + l + x + x) / 2.0;
    double A1 = sqrt(s1 * (s1 - a) * (s1 - l) * (s1 - l - x));
    double A2 = sqrt(s2 * (s2 - a) * (s2 - l) * (s2 - x));

    return A1 + A2;
}

int main() {
    int a, l, x;

    while(std::cin >> a >> l >> x) {
        double result = area(a, l, x);
        std::cout.precision(10);
        std::cout << result << std::endl;
    }

    return 0;
}