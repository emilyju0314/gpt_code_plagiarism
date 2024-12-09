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

        std::sort(a.begin(), a.end());

        bool possible = true;
        for (int i = 1; i < n; i++) {
            if (a[i] - a[i-1] > 1) {
                possible = false;
                break;
            }
        }

        if (possible) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}