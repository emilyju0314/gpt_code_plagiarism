#include <iostream>
#include <vector>
#include <algorithm>

bool is_square(const std::vector<std::pair<int, int>>& rectangles) {
    // Find the outer-most boundaries of the rectangles
    int min_x = rectangles[0].first;
    int max_x = rectangles[0].second;
    int min_y = rectangles[0].second;
    int max_y = rectangles[0].second;

    for (const auto& rect : rectangles) {
        min_x = std::min(min_x, rect.first);
        max_x = std::max(max_x, rect.second);
        min_y = std::min(min_y, rect.first);
        max_y = std::max(max_y, rect.second);
    }

    int side_length = std::max(max_x - min_x, max_y - min_y);

    // Check if the side length is the same for a square
    for (const auto& rect : rectangles) {
        if ((rect.second - rect.first) != side_length || (rect.second - rect.first) != (rect.second - rect.first)) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> rectangles;
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        rectangles.emplace_back(x1, x2);
        rectangles.emplace_back(y1, y2);
    }

    if (is_square(rectangles)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}