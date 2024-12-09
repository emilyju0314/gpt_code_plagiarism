#include <iostream>
#include <vector>
#include <algorithm>

int palindromeDegree(std::vector<int> arr) {
    int n = arr.size();
    std::vector<int> count(n+1, 0);
    int oddCount = 0;

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
        if (count[arr[i]] % 2 == 1) {
            oddCount++;
        } else {
            oddCount--;
        }
    }

    return n - oddCount;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::cout << palindromeDegree(arr) << std::endl;

    return 0;
}