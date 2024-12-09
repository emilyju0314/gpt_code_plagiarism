#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    long long operations = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] <= arr[i - 1]) {
            operations += abs(arr[i] - arr[i - 1]) + 1;
            arr[i] = arr[i - 1] + 1;
        }
    }

    std::cout << operations << std::endl;

    return 0;
}