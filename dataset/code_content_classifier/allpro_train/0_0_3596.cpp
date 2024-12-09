#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> slimes;
    slimes.push_back(1); // Initially we have one slime of value 1

    int curVal = 1;
    for (int i = 1; i < n; i++) {
        if (slimes.back() == curVal) {
            slimes.back()++;
            curVal++;
        } else {
            slimes.push_back(1);
            curVal = 1;
        }
    }

    for (int slime : slimes) {
        std::cout << slime << " ";
    }

    return 0;
}