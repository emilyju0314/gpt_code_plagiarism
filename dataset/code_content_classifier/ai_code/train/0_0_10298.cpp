#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int N, W, H;
    std::cin >> N >> W >> H;

    std::vector<std::pair<int, int>> corners;
    for (int i = 0; i < N; i++) {
        int x, y;
        std::cin >> x >> y;
        corners.push_back({x, y});
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        int next_x = corners[(i + 1) % N].first;
        int next_y = corners[(i + 1) % N].second;

        double dist = std::sqrt(std::pow(corners[i].first - next_x, 2) + std::pow(corners[i].second - next_y, 2));

        count += std::ceil(dist / W) - 1;
    }

    std::cout << count * H << std::endl;

    return 0;
}