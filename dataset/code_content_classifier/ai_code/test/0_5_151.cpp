#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int q;
    std::cin >> q;

    std::vector<int> arr;
    std::unordered_map<int, int> replace_map;

    for (int i = 0; i < q; ++i) {
        int type, x, y;
        std::cin >> type;

        if (type == 1) {
            std::cin >> x;
            arr.push_back(x);
        } else {
            std::cin >> x >> y;
            replace_map[x] = y;
        }
    }

    for (int num : arr) {
        if (replace_map.find(num) != replace_map.end()) {
            std::cout << replace_map[num] << " ";
        } else {
            std::cout << num << " ";
        }
    }

    return 0;
}