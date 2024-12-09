#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int k;
    std::cin >> k;

    std::vector<std::vector<int>> boxes(k);
    std::unordered_map<int, std::pair<int, int>> numToBoxIndex;

    for (int i = 0; i < k; ++i) {
        int n;
        std::cin >> n;
        boxes[i].resize(n);
        for (int j = 0; j < n; ++j) {
            std::cin >> boxes[i][j];
            numToBoxIndex[boxes[i][j]] = {i, j};
        }
    }

    int totalIntegers = 0;
    for (const auto& box : boxes) {
        totalIntegers += box.size();
    }

    if (totalIntegers % k != 0) {
        std::cout << "No" << std::endl;
    } else {
        int targetSum = totalIntegers / k;
        
        std::cout << "Yes" << std::endl;
        
        for (int i = 0; i < k; ++i) {
            for (const auto& num : boxes[i]) {
                int diff = targetSum - num;
                if (diff > num) {
                    auto[p, q] = numToBoxIndex[diff];
                    std::cout << num << " " << p + 1 << std::endl;
                    std::cout << diff << " " << i + 1 << std::endl;
                    break;
                }
            }
        }
    }

    return 0;
}