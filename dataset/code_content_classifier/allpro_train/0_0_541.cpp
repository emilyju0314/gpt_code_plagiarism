#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> names(n);
    std::unordered_map<char, int> firstLetterCount, lastLetterCount;

    for (int i = 0; i < n; i++) {
        std::cin >> names[i];
        firstLetterCount[names[i][0]]++;
        lastLetterCount[names[i][names[i].size() - 1]]++;
    }

    int maxDynastyLength = 0;

    for (int i = 0; i < n; i++) {
        if (firstLetterCount[names[i][names[i].size() - 1]] > 0) {
            maxDynastyLength = std::max(maxDynastyLength, (int)names[i].size());
        }
    }

    std::cout << maxDynastyLength << std::endl;

    return 0;
}