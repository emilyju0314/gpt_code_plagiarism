#include <iostream>
#include <vector>

int main() {
    int n, y1;
    std::cin >> n >> y1;

    std::vector<int> sensors_1(n);
    for (int i = 0; i < n; i++) {
        std::cin >> sensors_1[i];
    }

    int m, y2;
    std::cin >> m >> y2;

    std::vector<int> sensors_2(m);
    for (int i = 0; i < m; i++) {
        std::cin >> sensors_2[i];
    }

    // Calculate the maximum number of sensors that can register the laser ray
    int max_sensors = n + m; // at least both lines' sensors can register
    int max_x = sensors_1[n-1] + y2 - y1; // maximum x-coordinate for the ray direction

    for (int i = 1; i < m; i++) {
        int x1 = sensors_2[i] - sensors_2[i-1];
        if (x1 <= max_x) {
            // Increment the max_sensors count by 2 for the sensor pair at x1 position
            max_sensors += 2;
        }
    }

    std::cout << max_sensors << std::endl;

    return 0;
}