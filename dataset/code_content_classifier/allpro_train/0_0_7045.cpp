#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        std::cin >> sequence[i];
    }

    std::vector<int> count(8);
    for (int num : sequence) {
        count[num]++;
    }

    std::vector<std::vector<int>> groups;
    for (int i = 1; i <= 7; i++) {
        if (count[i] > count[i+1] || count[i] > 0) {
            std::cout << -1;
            return 0;
        }

        for (int j = 0; j < count[i]; j++) {
            groups.push_back({i, i*2, i*4});
            count[i*2]--;
            count[i*4]--;
        }
    }

    for (const auto& g : groups) {
        for (int num : g) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}