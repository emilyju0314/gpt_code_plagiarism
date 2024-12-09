#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> ratings(n);
    for (int i = 0; i < n; i++) {
        std::cin >> ratings[i];
    }

    std::unordered_map<int, int> rating_indices;
    for (int i = 0; i < n; i++) {
        if (rating_indices.find(ratings[i]) != rating_indices.end()) {
            continue;
        }
        rating_indices[ratings[i]] = i + 1;
    }

    if (rating_indices.size() < k) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;
        int count = 0;
        for (auto& kvp : rating_indices) {
            std::cout << kvp.second << " ";
            count++;
            if (count == k) {
                break;
            }
        }
        std::cout << std::endl;
    }

    return 0;
}