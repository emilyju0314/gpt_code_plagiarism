#include <iostream>
#include <vector>

bool isComposite(int num) {
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }

        int maxSubsetSize = 0;
        std::vector<int> subsetIndices;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    int sum = arr[i] + arr[j] + arr[k];
                    if (isComposite(sum) && maxSubsetSize < 3) {
                        maxSubsetSize = 3;
                        subsetIndices = {i+1, j+1, k+1};
                    }
                }
            }
        }

        std::cout << maxSubsetSize << std::endl;
        for (int i = 0; i < maxSubsetSize; i++) {
            std::cout << subsetIndices[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}