#include <iostream>
#include <vector>

bool isSorted(std::vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

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

        if (isSorted(arr)) {
            std::cout << "0\n";
            continue;
        }

        // Implement sorting logic here

    }

    return 0;
}