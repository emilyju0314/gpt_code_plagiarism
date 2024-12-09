#include <iostream>
#include <vector>

int main() {
    int n, k, l, r, sall, sk;
    std::cin >> n >> k >> l >> r >> sall >> sk;

    std::vector<int> points(n, l);
    for (int i = 0; i < k; i++) {
        points[i] = sk / k;
    }

    int remaining = sall - sk;
    for (int i = 0; i < n; i++) {
        if (i < k) {
            remaining += points[i] - l;
        } else {
            points[i] = l;
        }
    }

    for (int i = 0; i < n; i++) {
        int add = std::min(remaining, r - points[i]);
        points[i] += add;
        remaining -= add;
    }

    for (int i = 0; i < n; i++) {
        std::cout << points[i] << " ";
    }

    return 0;
}