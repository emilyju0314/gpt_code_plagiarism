#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        std::cin >> points[i].first >> points[i].second;
    }

    for (int i = 0; i < n; i++) {
        if ((points[i].first + points[i].second) % 2 == 0) {
            std::cout << "r";
        } else {
            std::cout << "b";
        }
    }

    return 0;
}