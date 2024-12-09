#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> boxes(n);
    for (int i = 0; i < n; i++) {
        std::cin >> boxes[i];
    }

    std::sort(boxes.begin(), boxes.end());

    int numVisible = 1;
    for (int i = 1; i < n; i++) {
        if (boxes[i] > boxes[i-1]) {
            numVisible++;
        }
    }

    std::cout << numVisible << std::endl;

    return 0;
}