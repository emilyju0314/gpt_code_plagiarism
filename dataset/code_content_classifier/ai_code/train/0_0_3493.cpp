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

    int max_xor = arr[0];
    int curr_xor = 0;

    for (int i = 0; i < n; i++) {
        curr_xor = 0;
        for (int j = i; j < n; j++) {
            curr_xor ^= arr[j];
            max_xor = std::max(max_xor, curr_xor);
        }
    }

    std::cout << max_xor << std::endl;

    return 0;
}