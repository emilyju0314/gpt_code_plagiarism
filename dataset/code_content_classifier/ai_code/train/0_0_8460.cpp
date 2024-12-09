#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    std::unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
        freq[arr[i]]++;
    }

    std::vector<int> result;

    for (int i = 0; i < n; i++) {
        if (freq[arr[i]] >= 2) {
            result.push_back(arr[i] * 2);
            freq[arr[i]] = 0;
        } else {
            result.push_back(arr[i]);
        }
    }

    int k = result.size();
    std::cout << k << std::endl;

    for (int i = 0; i < k; i++) {
        std::cout << result[i] << " ";
    }

    return 0;
}