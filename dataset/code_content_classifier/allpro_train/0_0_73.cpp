#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] <= k) {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}