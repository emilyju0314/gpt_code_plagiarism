#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> stack(n);
    for (int i = 0; i < n; i++) {
        std::cin >> stack[i];
    }

    std::unordered_map<int, int> index;
    for (int i = 0; i < n; i++) {
        int book;
        std::cin >> book;
        index[book] = i;
    }

    int maxIndex = 0;
    for (int i = 0; i < n; i++) {
        maxIndex = std::max(maxIndex, index[stack[i]]);

        std::cout << (maxIndex - i + 1) << " ";
    }

    return 0;
}