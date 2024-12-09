#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> problems(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> problems[i];
    }

    int m;
    std::cin >> m;

    std::vector<std::pair<int, int>> periods(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> periods[i].first >> periods[i].second;
    }

    int min_time = -1;
    for (int i = 0; i < m; ++i) {
        if (periods[i].second >= problems[n-1]) {
            min_time = std::max(min_time, periods[i].first);
        }
    }

    std::cout << min_time << std::endl;

    return 0;
}