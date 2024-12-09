#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> points(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> points[i];
    }

    std::vector<std::pair<int, int>> segments(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> segments[i].first >> segments[i].second;
    }

    std::vector<int> colors(n, 0);

    for (int i = 0; i < m; ++i) {
        for (int j = segments[i].first - 1; j < segments[i].second; ++j) {
            if (colors[j] == 0) {
                colors[j] = 1;
            } else {
                colors[j] = 0;
            }
        }
    }

    for (int color : colors) {
        std::cout << color << " ";
    }

    return 0;
}