#include <iostream>
#include <vector>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::string directions;
    std::cin >> directions;

    std::vector<int> jumpLengths(n);
    for (int i = 0; i < n; i++) {
        std::cin >> jumpLengths[i];
    }

    std::vector<bool> visited(n, false);
    int currentCell = 0;
    while (currentCell >= 0 && currentCell < n) {
        if (visited[currentCell]) {
            std::cout << "INFINITE" << std::endl;
            return 0;
        }
        visited[currentCell] = true;
        if (directions[currentCell] == '>') {
            currentCell += jumpLengths[currentCell];
        } else {
            currentCell -= jumpLengths[currentCell];
        }
    }

    std::cout << "FINITE" << std::endl;
    return 0;
}