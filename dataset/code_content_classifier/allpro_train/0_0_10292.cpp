#include <iostream>
#include <cmath>

int main() {
    double v;
    while (std::cin >> v) {
        // Calculate the time taken for the ball to reach the minimum velocity v
        double t = v / 9.8;
        
        // Calculate the height at which the ball will crack
        double y = 4.9 * pow(t, 2);
        
        // Calculate the floor where the ball will crack
        int floor = (y + 5) / 5;
        
        std::cout << floor << std::endl;
    }
    return 0;
}