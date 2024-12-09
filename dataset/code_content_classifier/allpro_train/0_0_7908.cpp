#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    int minTravelTime = INT_MAX;
    int minIndex = -1;
    int duplicate = 0;

    for (int i = 0; i < n; i++) {
        int travelTime;
        std::cin >> travelTime;

        if (travelTime < minTravelTime) {
            minTravelTime = travelTime;
            minIndex = i;
            duplicate = 0;
        } else if (travelTime == minTravelTime) {
            duplicate = 1;
        }
    }

    if (duplicate) {
        std::cout << "Still Rozdil" << std::endl;
    } else {
        std::cout << minIndex + 1 << std::endl;
    }

    return 0;
}