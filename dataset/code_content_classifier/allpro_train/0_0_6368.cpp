#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    // Sort the array to easily find the minimum and maximum elements
    std::sort(a.begin(), a.end());

    int diff = a[n-1] - a[0]; // Calculate the difference between the maximum and minimum elements

    // Check if the difference is divisible by (n-1)
    // If it is, then it is possible to make all elements equal
    // Otherwise, it is not possible
    if(diff % (n-1) == 0) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}