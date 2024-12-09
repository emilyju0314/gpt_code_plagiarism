#include <iostream>

int main() {
    int theta;
    std::cin >> theta;

    // Calculate hours and minutes based on the angle
    int hours = (theta / 30) % 12;
    int minutes = (theta % 30) * 2;

    // Output the time
    std::cout << hours << " " << minutes << std::endl;

    return 0;
}