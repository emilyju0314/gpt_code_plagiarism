#include <iostream>
#include <vector>
#include <map>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<std::pair<int, int>> ranges;
        for (int i = 0; i < n; ++i) {
            int l, r;
            std::cin >> l >> r;
            ranges.push_back({l, r});
        }

        std::map<std::pair<int, int>, int> d_map;

        for (int i = 0; i < n; ++i) {
            d_map[{ranges[i].first, ranges[i].second}] = ranges[i].first;
        }

        for (auto it = d_map.begin(); it != d_map.end(); ++it) {
            std::cout << it->first.first << " " << it->first.second << " " << it->second << std::endl;
        }
    }

    return 0;
}