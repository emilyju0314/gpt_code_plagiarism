#include <iostream>

int main() {
    int n, m, s;
    std::cin >> n >> m >> s;

    long long maxX = (n-1) * (m / s);
    long long maxY = (m-1) * (n / s);

    long long ans = (maxX + 1) * (maxY + 1);
    std::cout << ans << std::endl;

    return 0;
}