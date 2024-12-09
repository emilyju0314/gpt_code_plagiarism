#include <iostream>
#include <vector>
#include <unordered_map>

struct Tetrapod {
    int x1, y1, x2, y2, x3, y3;
};

bool isValidSolution(std::vector<Tetrapod>& tetrapods) {
    std::unordered_map<std::pair<int, int>, int> coverage;

    for (const auto& tetrapod : tetrapods) {
        coverage[{tetrapod.x2, tetrapod.y2}]++;
        coverage[{tetrapod.x3, tetrapod.y3}]++;

        if (coverage[{tetrapod.x2, tetrapod.y2}] > 1 || coverage[{tetrapod.x3, tetrapod.y3}] > 1) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::vector<Tetrapod> tetrapods(n);
        
        for (int i = 0; i < n; ++i) {
            std::cin >> tetrapods[i].x1 >> tetrapods[i].y1 >>
                        tetrapods[i].x2 >> tetrapods[i].y2 >>
                        tetrapods[i].x3 >> tetrapods[i].y3;
        }

        if (isValidSolution(tetrapods)) {
            std::cout << "Valid" << std::endl;
        } else {
            for (int i = 0; i < n; ++i) {
                std::vector<Tetrapod> tetrapods_copy = tetrapods;
                tetrapods_copy.erase(tetrapods_copy.begin() + i);
                if (isValidSolution(tetrapods_copy)) {
                    std::cout << "Remove" << std::endl;
                    std::cout << i + 1 << std::endl;
                    break;
                }
            }
            if (isValidSolution(tetrapods)) {
                std::cout << "Invalid" << std::endl;
            }
        }
    }

    return 0;
}