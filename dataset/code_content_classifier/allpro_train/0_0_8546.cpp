#include <iostream>
#include <cmath>

int main() {
    int n, m, x, y, vx, vy;
    std::cin >> n >> m >> x >> y >> vx >> vy;

    int dx = vx > 0 ? n - x : x;
    int dy = vy > 0 ? m - y : y;

    int steps_x = std::abs(dx) / std::abs(vx);
    int steps_y = std::abs(dy) / std::abs(vy);

    if (dx % vx != 0 || dy % vy != 0 || steps_x != steps_y) {
        std::cout << -1 << std::endl;
    } else {
        int side_x = dx > 0 ? 0 : 1;
        int side_y = dy > 0 ? 0 : 1;
        std::cout << side_x << " " << side_y << std::endl;
    }

    return 0;
}