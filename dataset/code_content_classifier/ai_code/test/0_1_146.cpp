#include <iostream>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
    }

    for (int i = 0; i < q; ++i) {
        int type;
        std::cin >> type;
        if (type == 1) {
            int x, y;
            std::cin >> x >> y;
            std::swap(p[x-1], p[y-1]);
        } else {
            int idx, k;
            std::cin >> idx >> k;
            int cur_idx = idx - 1;
            for (int j = 0; j < k; ++j) {
                cur_idx = p[cur_idx] - 1;
            }
            std::cout << p[cur_idx] << std::endl;
        }
    }

    return 0;
}