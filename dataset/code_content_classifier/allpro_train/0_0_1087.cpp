#include <iostream>

int main() {
    int n, k;
    std::cin >> n >> k;

    int max_rating = 0;
    for (int i = 0; i < n; i++) {
        int ai;
        std::cin >> ai;
        int improvement_needed = 100 - ai;
        int improvements_used = std::min(improvement_needed, k);
        k -= improvements_used;
        max_rating += ai + improvements_used;
    }

    std::cout << max_rating << std::endl;

    return 0;
}