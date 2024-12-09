#include <iostream>
#include <vector>
#include <algorithm>

struct Cell {
    int x, y, c;
};

int main() {
    int n;
    std::cin >> n;

    std::vector<Cell> cells(n);
    for (int i = 0; i < n; i++) {
        std::cin >> cells[i].x >> cells[i].y >> cells[i].c;
    }

    int k_max = 0;

    for (int k = 3; k <= n; k += 3) {
        do {
            std::vector<int> counts(3, 0);
            std::vector<int> mins(3, INT_MAX);
            std::vector<int> maxs(3, INT_MIN);

            for (int i = 0; i < k; i++) {
                counts[cells[i].c - 1]++;
                mins[cells[i].c - 1] = std::min(mins[cells[i].c - 1], cells[i].x);
                maxs[cells[i].c - 1] = std::max(maxs[cells[i].c - 1], cells[i].x);
            }

            if (counts[0] == k/3 && counts[1] == k/3 && counts[2] == k/3) {
                std::sort(mins.begin(), mins.end());
                std::sort(maxs.begin(), maxs.end());

                if (mins[1] > maxs[0] && mins[2] > maxs[1]) {
                    k_max = k;
                }
            }

        } while(std::next_permutation(cells.begin(), cells.end()));

    }

    std::cout << k_max << std::endl;

    return 0;
}