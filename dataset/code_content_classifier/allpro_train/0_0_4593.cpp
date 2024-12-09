#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> distinct(n);
    std::vector<int> equal(n);
    std::unordered_map<int, int> pos;

    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;

        pos[a] = i;
        pos[b] = i;
    }

    if (n <= m) {
        std::cout << "YES\n";

        for (int i = 0; i < n; i++) {
            distinct[i] = i + 1;
            equal[i] = i + 1;
        }

        for (auto p : pos) {
            equal[p.first - 1] = pos[p.first] % n + 1;
        }

        for (int i = 0; i < n; i++) {
            std::cout << distinct[i] << " ";
        }
        std::cout << "\n";

        for (int i = 0; i < n; i++) {
            std::cout << equal[i] << " ";
        }
        std::cout << "\n";
    } else {
        std::cout << "NO\n";
    }

    return 0;
}