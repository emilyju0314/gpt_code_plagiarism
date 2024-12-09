#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int minTime = 0;
    int nonZeroCount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            nonZeroCount++;
            minTime += std::abs(arr[i]);
        }
    }

    if (nonZeroCount > 1) {
        minTime++;
    }

    std::cout << minTime << std::endl;

    return 0;
}