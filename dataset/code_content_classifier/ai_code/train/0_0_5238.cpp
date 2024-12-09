#include <iostream>
#include <vector>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> sum(n+1, 0);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        sum[a] += c;
        sum[b+1] -= c;
    }

    int total = 0;
    for (int i = 1; i <= n; i++) {
        sum[i] += sum[i-1];
    }

    for (int i = 0; i < k; i++) {
        int cell;
        std::cin >> cell;
        total += sum[cell];
    }

    std::cout << total << std::endl;

    return 0;
}