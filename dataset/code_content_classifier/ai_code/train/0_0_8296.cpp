#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int Q;
    std::cin >> Q;

    std::vector<std::pair<int, int>> operations;
    for (int i = 0; i < Q; i++) {
        int m, x;
        std::cin >> m >> x;
        operations.push_back(std::make_pair(m, x));
    }

    int largest_term = 0;
    for (int i = 1; i <= 300; i++) {
        int current_term = 0;
        for (auto op : operations) {
            if (i % op.first == 0) {
                current_term += op.second;
            }
        }
        largest_term = std::max(largest_term, current_term);
    }

    std::cout << largest_term << std::endl;

    return 0;
}