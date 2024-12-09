#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, d;
    while (std::cin >> n >> d && n != 0 && d != 0) {
        std::vector<std::vector<int>> countries(n, std::vector<int>());
        for (int i = 0; i < n; ++i) {
            int mi;
            std::cin >> mi;
            for (int j = 0; j < mi; ++j) {
                int capability;
                std::cin >> capability;
                countries[i].push_back(capability);
            }
        }

        for (int i = 0; i < n; ++i) {
            std::reverse(countries[i].begin(), countries[i].end());
        }

        bool feasible = true;
        for (int i = 1; i < n; ++i) {
            int minPotential = 0, maxPotential = 0;
            for (int j = 0; j < countries[i].size(); ++j) {
                minPotential += countries[i][j];
            }
            for (int j = 0; j < countries[0].size(); ++j) {
                maxPotential += countries[0][j];
            }
            if (abs(minPotential - maxPotential) > d) {
                feasible = false;
                break;
            }
        }

        if (feasible) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }

    return 0;
}