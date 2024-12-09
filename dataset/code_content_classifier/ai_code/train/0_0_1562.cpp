#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> dices(n, std::vector<int>(6));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            std::cin >> dices[i][j];
        }
    }

    std::vector<std::set<int>> diceSets;
    for (int i = 0; i < n; i++) {
        std::set<int> diceSet;
        for (int j = 0; j < 6; j++) {
            diceSet.insert(dices[i][j]);
        }
        diceSets.push_back(diceSet);
    }

    std::sort(diceSets.begin(), diceSets.end());

    bool allDifferent = true;
    for (int i = 0; i < n - 1; i++) {
        if (diceSets[i] == diceSets[i + 1]) {
            allDifferent = false;
            break;
        }
    }

    if (allDifferent) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}