#include <iostream>
#include <cmath>

int main() {
    int a, b, l;
    double width;

    std::cin >> a >> b >> l;

    if (l <= a) {
        width = l;
    } else {
        double arctan_angle = atan((double)b / (double)a);
        double max_width = a + b * tan(arctan_angle);
        if (max_width < l) {
            std::cout << "My poor head =(" << std::endl;
            return 0;
        }

        width = l;
    }

    std::cout.precision(7);
    std::cout << std::fixed << width << std::endl;

    return 0;
}