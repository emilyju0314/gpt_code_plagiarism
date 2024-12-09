#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> set;
    std::vector<int> medians;

    for (int i = 0; i < n; ++i) {
        std::string operation;
        int x;
        std::cin >> operation;

        if (operation == "add") {
            std::cin >> x;
            set.push_back(x);
        } else if (operation == "del") {
            std::cin >> x;
            auto it = std::find(set.begin(), set.end(), x);
            if (it != set.end()) {
                set.erase(it);
            }
        } else if (operation == "sum") {
            std::sort(set.begin(), set.end());
            int sum = 0;
            int k = set.size() / 5;

            for (int j = 0; j < k; ++j) {
                medians.clear();
                for (int l = 0; l < 5; ++l) {
                    medians.push_back(set[j * 5 + l]);
                }
                std::sort(medians.begin(), medians.end());
                sum += medians[2];
            }

            std::cout << sum << std::endl;
        }
    }

    return 0;
}