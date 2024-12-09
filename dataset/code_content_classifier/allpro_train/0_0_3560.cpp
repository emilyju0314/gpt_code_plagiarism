#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<char, int> countMap;

    for (int i = 0; i < 3; i++) {
        std::string tile;
        std::cin >> tile;
        countMap[tile[0]]++;
    }

    int extraTiles = 2;
    for (auto& pair : countMap) {
        if (pair.second >= 3) {
            extraTiles = std::min(extraTiles, 0);
        } else if (pair.second == 2) {
            extraTiles = std::min(extraTiles, 1);
        } else {
            extraTiles = std::min(extraTiles, 2);
        }
    }

    std::cout << extraTiles << std::endl;

    return 0;
}