#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        for (int j = 0; j < n; j++) {
            std::cin >> a[j];
        }

        std::sort(a.begin(), a.end());

        for (int j = 0; j < n; j++) {
            std::cout << a[j] << " ";
        }

        std::cout << std::endl;
    }

    return 0;
}