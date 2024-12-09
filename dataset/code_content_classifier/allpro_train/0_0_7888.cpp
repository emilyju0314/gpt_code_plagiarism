#include <iostream>
#include <vector>
#include <algorithm>

int thanosSort(std::vector<int> arr) {
    int n = arr.size();

    // Check if array is already sorted
    bool isSorted = std::is_sorted(arr.begin(), arr.end());
    if (isSorted) {
        return n;
    }

    // Recursively split the array and check for sorted subarrays
    std::vector<int> firstHalf(arr.begin(), arr.begin() + n/2);
    std::vector<int> secondHalf(arr.begin() + n/2, arr.end());

    int ans = std::max(thanosSort(firstHalf), thanosSort(secondHalf));

    return ans;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int result = thanosSort(arr);
    std::cout << result << std::endl;

    return 0;
}