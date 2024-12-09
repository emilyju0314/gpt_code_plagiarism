#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> permutation(n);
    for (int i = 0; i < n; i++) {
        std::cin >> permutation[i];
    }

    for (int i = 0; i < m; i++) {
        int l, r, x;
        std::cin >> l >> r >> x;
        
        int target = permutation[x-1];
        int count = 0;
        for (int j = l-1; j < r; j++) {
            if (permutation[j] < target) {
                count++;
            }
        }

        if (count == x - l) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }

    return 0;
}