#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int l = -1, r = -1;

    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            if (l == -1) {
                l = i - 1;
            }
            r = i;
        }
    }

    if (l == -1) {
        std::cout << "yes\n1 1" << std::endl;
    } else {
        std::reverse(a.begin() + l, a.begin() + r + 1);
        bool sorted = std::is_sorted(a.begin(), a.end());

        if (sorted) {
            std::cout << "yes" << std::endl;
            std::cout << l + 1 << " " << r + 1 << std::endl;
        } else {
            std::cout << "no" << std::endl;
        }
    }

    return 0;
}