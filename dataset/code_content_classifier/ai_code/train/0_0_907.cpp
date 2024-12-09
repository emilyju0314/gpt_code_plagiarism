#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> permutation(n);

    permutation[0] = 1;
    int diff = k;

    for (int i = 1; i < n; i++) {
        if (diff > 0) {
            permutation[i] = permutation[i-1] + diff;
            diff *= -1;
        } else {
            permutation[i] = permutation[i-1] + 1;
        }
    }

    for (int num : permutation) {
        std::cout << num << " ";
    }
    
    return 0;
}