#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;

        std::vector<int> arr(n);
        for (int j = 0; j < n; j++) {
            std::cin >> arr[j];
        }

        std::sort(arr.begin(), arr.end());

        std::cout << arr[1] << std::endl; // Output the second smallest element after sorting
    }

    return 0;
}