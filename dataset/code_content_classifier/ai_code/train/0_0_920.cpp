#include <iostream>
#include <iomanip>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int a, b;
        std::cin >> a >> b;

        double p = (double)(a + 1) / (2 * b + 1);
        std::cout << std::fixed << std::setprecision(10) << p << std::endl;
    }

    return 0;
}