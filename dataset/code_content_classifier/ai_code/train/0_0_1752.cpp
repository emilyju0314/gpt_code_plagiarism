#include <iostream>
#include <vector>

std::vector<int> goodPermutation(int n) {
    std::vector<int> permutation(n);
    for (int i = 0; i < n; i++) {
        permutation[i] = i + 1;
    }
    return permutation;
}

int main() {
    int t;
    std::cin >> t; // Number of test cases

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> permutation = goodPermutation(n);
        for (int i = 0; i < n; i++) {
            std::cout << permutation[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}