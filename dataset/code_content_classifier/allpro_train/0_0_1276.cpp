#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 1e9 + 7;

struct Point {
    int x, y;
};

int calculateDistance(const Point& p1, const Point& p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Point> towers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> towers[i].x >> towers[i].y;
    }

    int minFee = 0;
    int count = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int fee = calculateDistance(towers[i], towers[j]);
            if (fee > minFee) {
                minFee = fee;
                count = 1;
            } else if (fee == minFee) {
                count++;
            }
        }
    }

    std::cout << minFee << std::endl;
    std::cout << count % MOD << std::endl;

    return 0;
}