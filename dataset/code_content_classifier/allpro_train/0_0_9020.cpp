#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    std::vector<long long> a(n);
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
        sum += a[i];
    }

    // Check if the array is already destroyed
    if(sum == 0) {
        std::cout << "0" << std::endl;
        return 0;
    }

    // Check if the array can be destroyed by type 1 operations
    if(n == 1) {
        std::cout << "1" << std::endl;
        return 0;
    }

    // For any other array, we can destroy all elements except one using the type 2 operations
    std::cout << n-1 << std::endl;

    return 0;
}