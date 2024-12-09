#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        int max_k = 1;
        int max_sum = a[0];
        int curr_sum = a[0];

        for (int i = 1; i < n; i++) {
            if (a[i] > a[i-1]) {
                curr_sum += a[i];
                max_k++;
                max_sum = std::max(max_sum, curr_sum);
            } else {
                curr_sum = a[i];
                max_k = 1;
            }
        }

        std::cout << max_k << std::endl;
    }

    return 0;
}