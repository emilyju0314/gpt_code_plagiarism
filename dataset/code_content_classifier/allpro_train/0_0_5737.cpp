#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    for (int i = 0; i < q; ++i) {
        int t, k;
        std::cin >> t >> k;

        if (t == 1) {
            a[k-1] = 1 - a[k-1];
        } else if (t == 2) {
            std::vector<int> sorted_a = a;
            std::sort(sorted_a.begin(), sorted_a.end(), std::greater<int>());
            std::cout << sorted_a[k-1] << std::endl;
        }
    }

    return 0;
}