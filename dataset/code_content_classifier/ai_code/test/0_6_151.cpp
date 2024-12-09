#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int q;
    std::cin >> q;
    
    std::vector<int> arr;
    std::unordered_map<int, int> replaceMap;

    for (int i = 0; i < q; i++) {
        int type;
        std::cin >> type;
        if (type == 1) {
            int x;
            std::cin >> x;
            arr.push_back(x);
        } else {
            int x, y;
            std::cin >> x >> y;
            replaceMap[x] = y;
        }
    }

    for (int i = 0; i < arr.size(); i++) {
        if (replaceMap.find(arr[i]) != replaceMap.end()) {
            arr[i] = replaceMap[arr[i]];
        }
    }

    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}