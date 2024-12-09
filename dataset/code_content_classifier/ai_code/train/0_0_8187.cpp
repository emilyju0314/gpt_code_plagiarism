#include <iostream>
#include <iomanip>

int main() {
    int d, h, v, e;
    std::cin >> d >> h >> v >> e;

    double r = d / 2.0;
    double area = 3.141592653589793 * r * r;
    
    double drinking_speed = v / area;
    double rain_increase_speed = e / area;
    
    if (drinking_speed >= rain_increase_speed) {
        double time_to_empty = h / (drinking_speed - rain_increase_speed);
        std::cout << "YES" << std::endl;
        std::cout << std::fixed << std::setprecision(12) << time_to_empty << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}