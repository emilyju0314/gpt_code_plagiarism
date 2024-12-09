#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, k;
        std::cin >> n >> k;

        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        int x;
        if (k == 0) {
            x = a[0];
        } else if (k == n-1) {
            x = a[n-1];
        } else {
            int d = (a[k] - a[k-1] + 1) / 2;
            x = a[k-1] + d;
        }

        std::cout << x << std::endl;
    }

    return 0;
}