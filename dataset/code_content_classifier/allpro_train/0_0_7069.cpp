#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, l, r;
    std::cin >> n >> l >> r;

    std::vector<int> heights(n);
    std::vector<int> importance(n);
    for (int i = 0; i < n; i++) {
        std::cin >> heights[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> importance[i];
    }

    int convenience = 0;
    int important_boxes = 0;
    for (int i = 0; i < n; i++) {
        if (importance[i] == 1 && heights[i] >= l && heights[i] <= r) {
            important_boxes++;
        }
    }

    convenience = std::min(important_boxes, std::max(0, (r - l + 1) - n + important_boxes));

    std::cout << convenience << std::endl;

    return 0;
}