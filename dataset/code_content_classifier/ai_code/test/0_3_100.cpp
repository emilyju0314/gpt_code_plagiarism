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

        int max_min = arr[n-1];
        for (int j = n-2; j >= 0; j--) {
            max_min = std::min(max_min, arr[j] + n - j - 1);
        }

        std::cout << max_min << std::endl;
    }

    return 0;
}