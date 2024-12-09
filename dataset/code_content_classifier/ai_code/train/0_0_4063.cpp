#include <iostream>
#include <cmath>

const double PI = acos(-1.0);

double calculateArea(int n) {
    double angle = 2 * PI / n;
    double side = sin(angle/2) / sin((PI - angle) / 2);
    double area = 0.5 * side * side * sin(angle);
    return area * n;
}

int main() {
    int n;

    while (true) {
        std::cin >> n;
        if (n == 0) {
            break;
        }

        double area = calculateArea(n);

        std::cout << area << std::endl;
    }

    return 0;
}