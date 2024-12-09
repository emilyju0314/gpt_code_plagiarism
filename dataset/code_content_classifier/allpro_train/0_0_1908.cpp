#include <iostream>
#include <vector>
#include <map>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::map<int, int> utensils_count;

    for (int i = 0; i < n; i++) {
        int utensil_type;
        std::cin >> utensil_type;
        utensils_count[utensil_type]++;
    }

    int stolen_utensils = 0;

    for (const auto& pair : utensils_count) {
        stolen_utensils += pair.second % k;
    }

    if (stolen_utensils % k == 0) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << k - stolen_utensils % k << std::endl;
    }

    return 0;
}