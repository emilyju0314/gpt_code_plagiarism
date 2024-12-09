#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m, c_l, c_e, v;
    std::cin >> n >> m >> c_l >> c_e >> v;

    std::vector<int> stairs(c_l), elevators(c_e);
    for (int i = 0; i < c_l; i++) {
        std::cin >> stairs[i];
    }
    for (int i = 0; i < c_e; i++) {
        std::cin >> elevators[i];
    }

    int q;
    std::cin >> q;

    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;

        int min_dist = std::abs(x1 - x2) + std::abs(y1 - y2); // Distance on the same floor

        // Calculate distance to the nearest stair
        int dist_to_stair = m;
        for (int stair : stairs) {
            int current_dist = std::abs(stair - y1) + std::abs(stair - y2);
            dist_to_stair = std::min(dist_to_stair, current_dist);
        }

        // Calculate distance to the nearest elevator
        int dist_to_elevator = n;
        for (int elevator : elevators) {
            int current_dist = std::abs(elevator - x1) + std::abs(elevator - x2);
            dist_to_elevator = std::min(dist_to_elevator, current_dist);
        }

        // Calculate total time required using stairs or elevator
        int time_stair = dist_to_stair + std::abs(x1 - x2);
        int time_elevator = dist_to_elevator * v + std::abs(y1 - y2);

        int min_time = std::min(min_dist, std::min(time_stair, time_elevator));
        std::cout << min_time << std::endl;
    }

    return 0;
}