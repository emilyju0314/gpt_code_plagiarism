#include <iostream>
#include <map>

int main() {
    int N;
    std::cin >> N;

    std::map<int, int> bars;
    for (int i = 0; i < N; i++) {
        int length;
        std::cin >> length;
        bars[length]++;
    }

    int maxHeight = 0;
    int totalTowers = 0;
    for (auto it = bars.begin(); it != bars.end(); it++) {
        maxHeight = std::max(maxHeight, it->second);
        if (it->second > 0) {
            totalTowers++;
        }
    }

    std::cout << maxHeight << " " << totalTowers << std::endl;

    return 0;
}