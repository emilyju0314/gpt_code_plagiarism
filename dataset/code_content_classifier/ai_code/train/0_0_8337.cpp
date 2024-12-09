#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> soldiers(n);
    for (int i = 0; i < n; i++) {
        std::cin >> soldiers[i];
    }

    int swaps = 0;
    for (int i = 0; i < n; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (soldiers[j] > soldiers[max_idx]) {
                max_idx = j;
            }
        }
        swaps += max_idx - i;
        std::swap(soldiers[i], soldiers[max_idx]);
    }

    std::cout << swaps << std::endl;

    return 0;
}