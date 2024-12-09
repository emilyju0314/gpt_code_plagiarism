#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n;
        std::cin >> n;

        std::vector<int> array(n);
        for(int i = 0; i < n; i++) {
            std::cin >> array[i];
        }

        std::sort(array.begin(), array.end());

        int maxMin = array[n-1]; // Start with the maximum element in the array

        for(int i = n-2; i >= 0; i--) {
            maxMin = std::min(maxMin, array[i] + n-1 - i); // Apply the operation to calculate the new maxMin
        }

        std::cout << maxMin << std::endl;
    }

    return 0;
}