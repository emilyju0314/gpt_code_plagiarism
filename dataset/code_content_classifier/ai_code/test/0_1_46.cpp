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
        int max_element = 0;

        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
            max_element = std::max(max_element, a[i]);
        }

        int eversions = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == max_element) {
                break;
            } else {
                eversions++;
            }
        }

        std::cout << eversions << std::endl;
    }

    return 0;
}