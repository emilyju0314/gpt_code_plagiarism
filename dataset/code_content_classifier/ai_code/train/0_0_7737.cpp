#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> sockets(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> sockets[i];
    }

    std::sort(sockets.rbegin(), sockets.rend());

    int needed_filters = 0;
    int total_sockets = k;

    for (int i = 0; i < n; ++i) {
        if (total_sockets >= m) {
            break;
        }

        if (sockets[i] > 1) {
            total_sockets += (sockets[i] - 1);
            needed_filters++;
        }
    }

    if (total_sockets >= m) {
        std::cout << needed_filters << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }

    return 0;
}