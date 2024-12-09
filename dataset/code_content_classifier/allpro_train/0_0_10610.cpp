#include <iostream>
#include <iomanip>

int main() {
    int l, p, q;
    std::cin >> l >> p >> q;

    double distance = (double)l*p / (p+q);

    std::cout << std::fixed << std::setprecision(4) << distance << std::endl;

    return 0;
}