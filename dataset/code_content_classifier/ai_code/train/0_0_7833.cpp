#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int max_remainder = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i] >= a[j]) {
                max_remainder = std::max(max_remainder, a[i] % a[j]);
            }
        }
    }

    std::cout << max_remainder << std::endl;

    return 0;
}