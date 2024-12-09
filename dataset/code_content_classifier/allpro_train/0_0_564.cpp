#include <iostream>
#include <vector>
#include <algorithm>

bool checkPossibility(std::vector<int>& initial_weights, std::vector<int>& final_weights) {
    std::vector<int> order;
    for (int i = 0; i < initial_weights.size(); ++i) {
        order.push_back(i);
    }

    std::vector<std::pair<int, char>> actions;

    while (initial_weights != final_weights) {
        bool found = false;
        for (int i = 0; i < order.size() - 1; ++i) {
            if (initial_weights[order[i]] > initial_weights[order[i+1]]) {
                std::swap(order[i], order[i+1]);
                actions.emplace_back(order[i], 'R');
                actions.emplace_back(order[i], 'L');
                found = true;
            }
        }
        
        if (!found) {
            return false;
        }
    }

    std::cout << "YES" << std::endl;
    for (const auto& action : actions) {
        std::cout << action.first + 1 << " " << action.second << std::endl;
    }

    return true;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> initial_weights(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> initial_weights[i];
    }

    int k;
    std::cin >> k;

    std::vector<int> final_weights(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> final_weights[i];
    }

    if (!checkPossibility(initial_weights, final_weights)) {
        std::cout << "NO" << std::endl;
    }

    return 0;
}