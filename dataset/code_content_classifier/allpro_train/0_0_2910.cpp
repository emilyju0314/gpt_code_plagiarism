#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int maxPossible = arr[0];
    if(k == 1) {
        for(int i = 1; i < n; i++) {
            maxPossible = std::max(maxPossible, arr[i]);
        }
    } else {
        int minVal = arr[0];
        for(int i = 0; i < n; i++) {
            minVal = std::min(minVal, arr[i]);
            if(i != 0) {
                maxPossible = std::max(maxPossible, minVal);
            }
        }
        maxPossible = std::max(maxPossible, arr[n-1]);
    }

    std::cout << maxPossible << std::endl;

    return 0;
}