#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::vector<std::pair<int, int>> swaps;
    for (int i = 0; i < n; i++) {
        int min_elem_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_elem_idx]) {
                min_elem_idx = j;
            }
        }
        if (i != min_elem_idx) {
            swaps.push_back({i, min_elem_idx});
            std::swap(arr[i], arr[min_elem_idx]);
        }
    }

    std::cout << swaps.size() << std::endl;
    for (auto swap : swaps) {
        std::cout << swap.first << " " << swap.second << std::endl;
    }

    return 0;
}