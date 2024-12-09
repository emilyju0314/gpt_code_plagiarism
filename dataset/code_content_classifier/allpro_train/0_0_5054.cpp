#include <iostream>
#include <vector>
#include <algorithm>

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> room(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> room[i][j];
        }
    }

    std::vector<int> distances;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (room[i][j] == 1) {
                int up = i, down = n - 1 - i, left = j, right = m - 1 - j;
                distances.push_back(std::min({up, down, left, right}));
            }
        }
    }

    if (distances.empty()) {
        std::cout << -1 << std::endl;
    } else {
        int current_gcd = distances[0];
        for (int i = 1; i < distances.size(); i++) {
            current_gcd = gcd(current_gcd, distances[i]);
        }

        for (int i = 2; i <= current_gcd; i++) {
            if (current_gcd % i == 0) {
                std::cout << i << " ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}