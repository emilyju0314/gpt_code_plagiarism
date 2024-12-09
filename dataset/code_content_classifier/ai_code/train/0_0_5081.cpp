#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        std::cin >> sequence[i];
    }

    std::unordered_map<int, int> fingerprints;
    for (int i = 0; i < m; i++) {
        int key;
        std::cin >> key;
        fingerprints[key] = i;
    }

    std::vector<int> code;
    for (int digit : sequence) {
        if (fingerprints.count(digit) > 0) {
            code.push_back(digit);
        }
    }

    for (int i = 0; i < code.size(); i++) {
        std::cout << code[i];
        if (i < code.size() - 1) {
            std::cout << " ";
        }
    }

    return 0;
}