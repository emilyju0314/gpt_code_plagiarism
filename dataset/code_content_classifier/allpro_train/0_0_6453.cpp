#include <iostream>

int main() {
    long long m;
    std::cin >> m;

    long long total_volume = 0;
    long long blocks = 0;

    for (int i = 1; total_volume + i * i * i <= m; i++) {
        total_volume += i * i * i;
        blocks++;
    }

    std::cout << blocks << " " << total_volume << std::endl;

    return 0;
}