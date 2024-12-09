#include <iostream>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;

    std::unordered_map<int, int> x_count, y_count;

    for (int i = 0; i < 4*n + 1; i++) {
        int x, y;
        std::cin >> x >> y;
        x_count[x]++;
        y_count[y]++;
    }

    int unique_x, unique_y;
    for (auto p : x_count) {
        if (p.second % 2 != 0) {
            unique_x = p.first;
            break;
        }
    }

    for (auto p : y_count) {
        if (p.second % 2 != 0) {
            unique_y = p.first;
            break;
        }
    }

    std::cout << unique_x << " " << unique_y << std::endl;

    return 0;
}