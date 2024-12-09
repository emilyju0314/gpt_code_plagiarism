#include <iostream>
#include <vector>

int main() {
    int n, m, h;
    std::cin >> n >> m >> h;

    std::vector<int> s(m);
    for (int i = 0; i < m; i++) {
        std::cin >> s[i];
    }

    int total_players = 0;
    for (int i = 0; i < m; i++) {
        total_players += s[i];
    }

    if (total_players < n) {
        std::cout << -1 << std::endl;
        return 0;
    }

    double result = 1.0;
    s[h-1]--;
    total_players--;

    for (int i = 0; i < n-1; i++) {
        result *= static_cast<double>(total_players - s[h-1] - i) / (total_players - i);
    }

    std::cout << 1 - result << std::endl;

    return 0;
}