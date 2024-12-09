#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    std::vector<int> b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    int total_ink = 0;
    for (int i = 0; i < m/2; i++) {
        int min_ink = std::min(a[0], b[0]);
        total_ink += min_ink;
    }

    std::cout << total_ink * m << std::endl;

    return 0;
}