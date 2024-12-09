#include <iostream>
#include <vector>

std::vector<int> beautifulPermutation(int n) {
    std::vector<int> permutation(n);
    for (int i = 0; i < n; ++i) {
        permutation[i] = i + 1;
    }
    for (int k = 2; k <= n; ++k) {
        std::vector<int> newPermutation(n);
        int r = n / k;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < k; ++j) {
                newPermutation[i * k + j] = permutation[i * k + (k - 1 - j)];
            }
        }
        for (int i = r * k; i < n; ++i) {
            newPermutation[i - (n % k)] = permutation[i];
        }
        permutation = newPermutation;
    }
    return permutation;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> result = beautifulPermutation(n);
    for (int i = 0; i < n; ++i) {
        std::cout << result[i] << " ";
    }
    
    return 0;
}