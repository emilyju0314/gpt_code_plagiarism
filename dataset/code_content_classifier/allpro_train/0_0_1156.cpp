#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::unordered_map<int, std::vector<int>> sumIndices;
    std::vector<int> a(n);

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            sumIndices[a[i] + a[j]].push_back(i);
            sumIndices[a[i] + a[j]].push_back(j);
        }
    }

    for (const auto& pair : sumIndices) {
        if (pair.second.size() >= 4) {
            std::cout << "YES" << std::endl;
            for (int i = 0; i < 4; i++) {
                std::cout << pair.second[i] + 1 << " ";
            }
            return 0;
        }
    }

    std::cout << "NO" << std::endl;

    return 0;
}