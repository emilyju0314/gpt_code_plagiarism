#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    int W, H, x, y;
    std::cin >> W >> H >> x >> y;

    double max_area = (double)W * H / 2;
    int multiple_ways = (x == W / 2 && y == H / 2) ? 1 : 0;

    std::cout << std::fixed << std::setprecision(9) << max_area << " " << multiple_ways << std::endl;

    return 0;
}