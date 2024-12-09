#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> segments;
    for (int i = 0; i < n; i++) {
        int l, r;
        std::cin >> l >> r;
        segments.push_back({l, r});
    }

    std::vector<int> points;
    for (int x = 1; x <= m; x++) {
        bool belongs_to_segment = false;
        for (const auto& segment : segments) {
            if (x >= segment.first && x <= segment.second) {
                belongs_to_segment = true;
                break;
            }
        }
        if (!belongs_to_segment) {
            points.push_back(x);
        }
    }

    std::cout << points.size() << std::endl;
    for (int point : points) {
        std::cout << point << " ";
    }

    return 0;
}