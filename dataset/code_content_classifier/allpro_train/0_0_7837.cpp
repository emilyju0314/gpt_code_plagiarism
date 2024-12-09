#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> cars(n);
    std::unordered_map<int, int> positions;

    for (int i = 0; i < n; i++) {
        std::cin >> cars[i];
        positions[cars[i]] = i;
    }

    int max_pos = -1;
    int moves = 0;

    for (int i = 0; i < n; i++) {
        if (positions[cars[i]] < max_pos) {
            moves++;
        }
        max_pos = std::max(max_pos, positions[cars[i]]);
    }

    std::cout << moves << std::endl;

    return 0;
}