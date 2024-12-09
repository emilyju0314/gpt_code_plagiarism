#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> q(n - 1);
    for (int i = 0; i < n - 1; i++) {
        std::cin >> q[i];
    }

    std::vector<int> p(n);

    p[0] = 1;
    for (int i = 1; i < n; i++) {
        p[i] = p[i - 1] + q[i - 1];
    }

    std::vector<bool> used(n + 1);
    for (int i = 0; i < n; i++) {
        if (p[i] < 1 || p[i] > n || used[p[i]]) {
            std::cout << "-1" << std::endl;
            return 0;
        }
        used[p[i]] = true;
    }

    for (int i = 0; i < n; i++) {
        std::cout << p[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}