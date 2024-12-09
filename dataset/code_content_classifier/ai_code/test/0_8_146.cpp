#include <iostream>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }

    for (int i = 0; i < q; i++) {
        int t;
        std::cin >> t;

        if (t == 1) {
            int x, y;
            std::cin >> x >> y;
            std::swap(p[x-1], p[y-1]);
        } else if (t == 2) {
            int i, k;
            std::cin >> i >> k;
            for (int j = 0; j < k; j++) {
                i = p[i-1];
            }
            std::cout << i << std::endl;
        }
    }

    return 0;
}