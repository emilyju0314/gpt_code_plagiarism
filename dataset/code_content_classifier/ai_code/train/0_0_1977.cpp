#include <iostream>
#include <iomanip>

int main() {
    double a, b, c, d, e, f;
    
    while (std::cin >> a >> b >> c >> d >> e >> f) {
        double x = (c*e - b*f) / (a*e - b*d);
        double y = (a*f - c*d) / (a*e - b*d);
        
        std::cout << std::fixed << std::setprecision(3) << x << ' ' << y << std::endl;
    }
    
    return 0;
}