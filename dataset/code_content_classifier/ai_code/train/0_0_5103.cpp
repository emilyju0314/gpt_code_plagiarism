#include <iostream>
#include <cmath>

int main() {
    int w, h, v, t, x, y, p, q;
    std::cin >> w >> h >> v >> t >> x >> y >> p >> q;

    long double count = 0;
    for(int dx = -1; dx <= 1; dx += 2) {
        for(int dy = -1; dy <= 1; dy += 2) {
            long double vx = dx == -1 ? x : w - x;
            long double vy = dy == -1 ? y : h - y;

            long double time = v * t / sqrt(vx * vx + vy * vy);
            int times = floor(t / time);

            count += times;
        }
    }

    std::cout << count << std::endl;

    return 0;
}