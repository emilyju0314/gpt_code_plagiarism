#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::unordered_map<int, int> occurrence;
    for (int i = 0; i < k; i++) {
        occurrence[arr[i]]++;
    }

    for (int i = k; i <= n; i++) {
        int max = -1;
        for (auto &it : occurrence) {
            if (it.second == 1 && (max == -1 || it.first > max)) {
                max = it.first;
            }
        }

        if (max != -1) {
            std::cout << max << std::endl;
        } else {
            std::cout << "Nothing" << std::endl;
        }

        if (i < n) {
            occurrence[arr[i - k]]--;
            if (occurrence[arr[i - k]] == 0) {
                occurrence.erase(arr[i - k]);
            }
            occurrence[arr[i]]++;
        }
    }

    return 0;
}