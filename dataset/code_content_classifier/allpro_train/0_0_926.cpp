#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, r;
    long long k;
    
    std::cin >> n >> r >> k;

    std::vector<int> archers(n);
    for (int i = 0; i < n; i++) {
        std::cin >> archers[i];
    }

    int low = 0, high = n, result = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        long long additional_archers = 0;
        for (int i = 0; i < n; i++) {
            if (archers[i] < mid) {
                additional_archers += mid - archers[i];
            }
        }

        if (additional_archers <= k) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    std::cout << result << std::endl;

    return 0;
}