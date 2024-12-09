#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int largestNonPerfectSquare = -1;
    for (int i = 0; i < n; i++) {
        int sqrtVal = sqrt(arr[i]);
        if (sqrtVal * sqrtVal != arr[i]) {
            largestNonPerfectSquare = std::max(largestNonPerfectSquare, arr[i]);
        }
    }

    std::cout << largestNonPerfectSquare << std::endl;

    return 0;
}