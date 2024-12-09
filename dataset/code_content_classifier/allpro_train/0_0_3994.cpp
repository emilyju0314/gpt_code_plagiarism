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

    std::sort(arr.begin(), arr.end());

    bool possible = false;
    for (int i = 0; i < n-1; i++) {
        if (arr[i] + arr[i+1] <= arr[n-1]) {
            possible = true;
            break;
        }
    }

    if (possible) {
        std::cout << "YES" << std::endl;
        for (int i = n-1; i >= 0; i--) {
            std::cout << arr[i] << " ";
        }
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}