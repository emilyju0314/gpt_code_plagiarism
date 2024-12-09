#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> array(n);
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }

    for (int i = 0; i < q; i++) {
        int l, r, k;
        std::cin >> l >> r >> k;

        std::unordered_map<int, int> freq_map;
        for (int j = l - 1; j < r; j++) {
            freq_map[array[j]]++;
            if (freq_map[array[j]] > (r - l + 1) / k) {
                std::cout << array[j] << std::endl;
                break;
            }
        }
        if (freq_map[array[l-1]] <= (r - l + 1) / k) {
            std::cout << -1 << std::endl;
        }
    }

    return 0;
}