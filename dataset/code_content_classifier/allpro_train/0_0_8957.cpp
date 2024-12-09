#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, l, x, y;
    std::cin >> n >> l >> x >> y;

    std::vector<int> marks(n);
    for (int i = 0; i < n; i++) {
        std::cin >> marks[i];
    }

    bool has_x = false, has_y = false;
    bool has_x_and_y = false;
    int ans = 0;
    int x_pos = -1, y_pos = -1;

    for (int i = 0; i < n; i++) {
        if (std::binary_search(marks.begin(), marks.end(), marks[i] + x)) {
            has_x = true;
            x_pos = marks[i];
        }
        if (std::binary_search(marks.begin(), marks.end(), marks[i] + y)) {
            has_y = true;
            y_pos = marks[i];
        }
        if (std::binary_search(marks.begin(), marks.end(), marks[i] + x + y)) {
            has_x_and_y = true;
        }
    }

    if (has_x && has_y) {
        std::cout << "0\n";
    } else if (has_x || has_y) {
        std::cout << "1\n";
        if (has_x) {
            std::cout << y << "\n";
        } else {
            std::cout << x << "\n";
        }
    } else if (has_x_and_y) {
        std::cout << "1\n";
        std::cout << (x < y ? x : y) << "\n";
    } else {
        ans = 2;
        std::cout << "2\n";
        std::cout << x << " " << y << "\n";
    }
    
    return 0;
}