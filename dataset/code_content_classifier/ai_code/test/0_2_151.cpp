#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int q;
    std::cin >> q;

    std::vector<int> result;
    std::unordered_map<int, int> replacements;

    for(int i = 0; i < q; i++) {
        int type;
        std::cin >> type;

        if(type == 1) {
            int x;
            std::cin >> x;
            result.push_back(x);
        } else if(type == 2) {
            int x, y;
            std::cin >> x >> y;
            replacements[x] = y;
        }
    }

    for(auto& num : result) {
        if(replacements.find(num) != replacements.end()) {
            num = replacements[num];
        }
        std::cout << num << " ";
    }

    return 0;
}