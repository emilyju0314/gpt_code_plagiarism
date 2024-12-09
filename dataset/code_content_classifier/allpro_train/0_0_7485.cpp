#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> levels(n);
    for (int i = 0; i < n; i++) {
        std::cin >> levels[i];
    }

    for (int i = 0; i < q; i++) {
        int b;
        std::cin >> b;

        int total_size = 0;
        int current_groups = 1;

        for (int j = 0; j < n; j++) {
            if (levels[j] + total_size > b) {
                current_groups++;
                total_size = 0;
            }
            total_size += levels[j];
        }

        std::cout << current_groups << std::endl;
    }

    return 0;
}