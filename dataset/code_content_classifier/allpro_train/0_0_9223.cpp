#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> houses(n);
    for (int i = 0; i < n; i++) {
        std::cin >> houses[i];
    }

    int maxFloors = 0;
    std::vector<int> additions(n);
    for (int i = n - 1; i >= 0; i--) {
        if (houses[i] <= maxFloors) {
            additions[i] = maxFloors - houses[i] + 1;
        } else {
            maxFloors = houses[i];
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << additions[i] << " ";
    }

    return 0;
}