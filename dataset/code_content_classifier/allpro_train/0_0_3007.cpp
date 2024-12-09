#include <iostream>
#include <cmath>

int main() {
    int AB, BC, CA;
    std::cin >> AB >> BC >> CA;

    int area = (AB * BC) / 2;
    std::cout << area << std::endl;

    return 0;
}