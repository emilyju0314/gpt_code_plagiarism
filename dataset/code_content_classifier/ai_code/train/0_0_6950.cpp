#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::unordered_map<int, std::vector<int>> markers;
    std::unordered_map<int, std::vector<int>> caps;

    for (int i = 0; i < n; ++i) {
        int xi, yi;
        std::cin >> xi >> yi;
        markers[yi].push_back(xi);
    }

    for (int i = 0; i < m; ++i) {
        int aj, bj;
        std::cin >> aj >> bj;
        caps[bj].push_back(aj);
    }

    int total_closed = 0, beautifully_closed = 0;

    for (auto it = markers.begin(); it != markers.end(); ++it) {
        int yi = it->first;
        if (caps.find(yi) != caps.end()) {
            std::vector<int>& marker_colors = it->second;
            std::vector<int>& cap_colors = caps[yi];

            int closed = std::min(marker_colors.size(), cap_colors.size());
            total_closed += closed;

            for (int j = 0; j < closed; ++j) {
                if (marker_colors[j] == cap_colors[j]) {
                    beautifully_closed++;
                }
            }
        }
    }

    std::cout << total_closed << " " << beautifully_closed << std::endl;

    return 0;
}