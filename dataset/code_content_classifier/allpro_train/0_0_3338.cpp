#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    std::string row;
    std::cin >> n >> row;

    std::vector<int> groups;
    int currentGroup = 0;

    for (int i = 0; i < n; i++) {
        if (row[i] == 'B') {
            currentGroup++;
        } else if (currentGroup > 0) {
            groups.push_back(currentGroup);
            currentGroup = 0;
        }
    }

    if (currentGroup > 0) {
        groups.push_back(currentGroup);
    }

    std::cout << groups.size() << std::endl;
    for (int group : groups) {
        std::cout << group << " ";
    }

    return 0;
}