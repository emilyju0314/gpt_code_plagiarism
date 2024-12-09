#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::string stages;
    std::cin >> stages;

    std::vector<int> weights;
    for (int i = 0; i < 26; i++) {
        if (stages.find('a'+i) != std::string::npos) {
            weights.push_back(i + 1);
        }
    }

    int minWeight = std::numeric_limits<int>::max();
    do {
        int weight = 0;
        bool valid = true;
        for (int i = 0; i < k; i++) {
            if (i == 0) {
                weight += weights[i];
            } else {
                if (weights[i] < weights[i-1] + 2) {
                    valid = false;
                    break;
                } else {
                    weight += weights[i];
                }
            }
        }

        if (valid && k <= weights.size()) {
            minWeight = std::min(minWeight, weight);
        }
    } while (std::next_permutation(weights.begin(), weights.end()));

    if (minWeight == std::numeric_limits<int>::max()) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << minWeight << std::endl;
    }

    return 0;
}