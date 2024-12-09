#include <iostream>
#include <vector>
#include <cmath>

struct Circle {
    int x, y, r;
};

bool intersects(Circle c1, Circle c2) {
    int dist_sq = (c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y);
    int rad_sum_sq = (c1.r + c2.r) * (c1.r + c2.r);
    return dist_sq <= rad_sum_sq;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<Circle> circles(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> circles[i].x >> circles[i].y >> circles[i].r;
    }

    int result = N;
    for (int i = 0; i < (1 << N); ++i) {
        std::vector<Circle> selected_circles;
        for (int j = 0; j < N; ++j) {
            if (i & (1 << j)) {
                selected_circles.push_back(circles[j]);
            }
        }

        bool isValid = true;
        for (int j = 0; j < selected_circles.size(); ++j) {
            for (int k = j + 1; k < selected_circles.size(); ++k) {
                if (!intersects(selected_circles[j], selected_circles[k])) {
                    isValid = false;
                    break;
                }
            }
            if (!isValid) break;
        }

        if (isValid) {
            int intersected_circles = __builtin_popcount(i);
            result = std::min(result, N - intersected_circles);
        }
    }

    std::cout << result << std::endl;

    return 0;
}