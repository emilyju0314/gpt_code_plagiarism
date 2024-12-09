#include <iostream>
#include <cmath>

int main() {
    int theta1, theta2;
    std::cin >> theta1 >> theta2;

    int difference = abs(theta1 - theta2);

    // Calculate the angle between theta1 and theta2
    int middle = (theta1 + theta2) / 2;
    if (middle >= 360) {
        middle -= 360;
    }

    // Output the angle between theta1 and theta2
    std::cout << middle << std::endl;

    return 0;
}