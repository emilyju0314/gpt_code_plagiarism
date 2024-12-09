#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> angles(n);
    for (int i = 0; i < n; i++) {
        std::cin >> angles[i];
    }

    int total_angle = 0;
    for (int angle : angles) {
        total_angle += angle;
    }

    int diff = total_angle;
    int current_angle = 0;

    for (int i = 0; i < n; i++) {
        current_angle += angles[i];
        diff = std::min(diff, std::abs(2 * current_angle - total_angle));
    }

    std::cout << diff << std::endl;

    return 0;
}