#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> chests(n);
    for (int i = 0; i < n; i++) {
        std::cin >> chests[i];
    }

    std::vector<int> keys(m);
    for (int i = 0; i < m; i++) {
        std::cin >> keys[i];
    }

    std::unordered_map<int, int> chestFrequency;
    for (int i = 0; i < n; i++) {
        chestFrequency[chests[i] % 2]++;
    }

    std::unordered_map<int, int> keyFrequency;
    for (int i = 0; i < m; i++) {
        keyFrequency[keys[i] % 2]++;
    }

    int maxChestsOpened = std::min(chestFrequency[0], keyFrequency[1]) + std::min(chestFrequency[1], keyFrequency[0]);

    std::cout << maxChestsOpened << std::endl;

    return 0;
}