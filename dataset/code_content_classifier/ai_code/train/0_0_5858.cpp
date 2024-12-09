#include <iostream>
#include <cmath>

int main() {
    int n, m, a, b;
    std::cin >> n >> m >> a >> b;

    int row_a = (a - 1) / m;
    int row_b = (b - 1) / m;

    int ans = std::ceil((double)(row_b - row_a + 1) / (double)m);

    std::cout << ans << std::endl;

    return 0;
}