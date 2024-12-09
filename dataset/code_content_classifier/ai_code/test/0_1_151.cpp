#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int q;
    std::cin >> q;

    std::vector<int> result;
    std::unordered_map<int, int> replacements;

    while (q--) {
        int type, x, y;
        std::cin >> type >> x;

        if (type == 1) {
            result.push_back(x);
        } else {
            std::cin >> y;
            replacements[x] = y;
        }
    }

    for (int i = 0; i < result.size(); i++) {
        if (replacements.find(result[i]) != replacements.end()) {
            result[i] = replacements[result[i]];
        }
        std::cout << result[i] << " ";
    }

    return 0;
}