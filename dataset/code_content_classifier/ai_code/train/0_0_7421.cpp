#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::map<std::string, int> countMap;

    for (int i = 0; i < N; i++) {
        std::string s;
        std::cin >> s;
        countMap[s]++;
    }

    int maxCount = 0;
    for (const auto &pair : countMap) {
        maxCount = std::max(maxCount, pair.second);
    }

    for (auto it = countMap.begin(); it != countMap.end(); ++it) {
        if (it->second == maxCount) {
            std::cout << it->first << std::endl;
        }
    }

    return 0;
}