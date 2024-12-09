#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    bool sorted = true;
    for (int i = 0; i < n - 1; i++) {
        if (std::abs(arr[i] - arr[i + 1]) >= 2) {
            sorted = false;
            break;
        }
    }

    if (sorted) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}