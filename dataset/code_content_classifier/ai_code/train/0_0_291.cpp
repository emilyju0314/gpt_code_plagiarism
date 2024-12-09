#include <iostream>
#include <algorithm>

int main() {
    int HPY, ATKY, DEFY;
    int HPM, ATKM, DEFM;
    int h, a, d;

    // Input
    std::cin >> HPY >> ATKY >> DEFY;
    std::cin >> HPM >> ATKM >> DEFM;
    std::cin >> h >> a >> d;

    // Calculate minimum bitcoins Master Yang should spend
    int minBitcoins = 0;

    // If Master Yang's offensive power is less than monster's defensive power
    if (ATKY <= DEFM) {
        minBitcoins += (DEFM - ATKY + 1) * a; // Buy enough ATK to defeat the monster
    }

    // If monster's offensive power is greater than or equal to Master Yang's defensive power
    if (ATKM >= DEFY) {
        minBitcoins += std::max(HPM - ATKY + 1, 0) * h; // Buy enough HP to survive
    }

    std::cout << minBitcoins << std::endl;

    return 0;
}