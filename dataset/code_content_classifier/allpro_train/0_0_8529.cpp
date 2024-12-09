#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> p(n), s(n);
    for(int i = 0; i < n; i++) {
        std::cin >> p[i];
    }

    for(int i = 0; i < n; i++) {
        std::cin >> s[i];
    }

    int coins = 0;
    std::vector<std::pair<int, int>> swaps;

    for(int i = 0; i < n; i++) {
        if(p[i] != s[i]) {
            int pos = std::find(p.begin(), p.end(), s[i]) - p.begin();
            std::swap(p[i], p[pos]);
            swaps.push_back({i+1, pos+1});
            coins += std::abs(i - pos);
        }
    }

    std::cout << coins << std::endl;
    std::cout << swaps.size() << std::endl;

    for(const auto& swap : swaps) {
        std::cout << swap.first << " " << swap.second << std::endl;
    }

    return 0;
}