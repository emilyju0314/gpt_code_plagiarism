#include <iostream>
#include <cmath>

int main() {
    int h1, h2, a, b;
    std::cin >> h1 >> h2 >> a >> b;

    int day = 0;
    int currentHeight = h1;
    while(currentHeight < h2) {
        day++;

        // Calculate the height at 10pm
        int heightAtNight = currentHeight + a*8 - b*6;

        // If height at night is enough to reach the apple, break the loop
        if(heightAtNight >= h2) {
            break;
        }

        currentHeight += a*12 - b*12; // Caterpillar climbs during the day and slips at night
    }

    if(currentHeight >= h2) {
        std::cout << day << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }

    return 0;
}