#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                std::cout << abs(arr[i]) << " ";
            } else {
                std::cout << -abs(arr[i]) << " ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}