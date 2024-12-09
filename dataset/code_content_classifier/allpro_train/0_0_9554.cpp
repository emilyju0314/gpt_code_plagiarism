#include <iostream>
#include <vector>
#include <unordered_map>

bool canAchieveDesiredColoring(int n, int m, std::vector<int>& initialColors, std::vector<int>& desiredColors, std::vector<int>& painters) {
    std::unordered_map<int, int> indexMap; // map each color to the index of corresponding plank
    std::vector<int> colorsToPaint(n, -1); // initialize all planks as not painted

    for (int i = 0; i < n; i++) {
        indexMap[initialColors[i]] = i;
    }

    for (int i = 0; i < m; i++) {
        int color = painters[i];
        if (indexMap.find(color) != indexMap.end()) {
            colorsToPaint[indexMap[color]] = color;
        }
    }

    for (int i = 0; i < n; i++) {
        if (colorsToPaint[i] == -1 && initialColors[i] != desiredColors[i]) {
            return false;
        }
    }

    std::cout << "YES" << std::endl;
    for (int i = 0; i < m; i++) {
        std::cout << indexMap[painters[i]] + 1 << " ";
    }
    std::cout << std::endl;

    return true;
}

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m;
        std::cin >> n >> m;

        std::vector<int> initialColors(n);
        std::vector<int> desiredColors(n);
        std::vector<int> painters(m);

        for (int j = 0; j < n; j++) {
            std::cin >> initialColors[j];
        }

        for (int j = 0; j < n; j++) {
            std::cin >> desiredColors[j];
        }

        for (int j = 0; j < m; j++) {
            std::cin >> painters[j];
        }

        if (!canAchieveDesiredColoring(n, m, initialColors, desiredColors, painters)) {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}