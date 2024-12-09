#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::vector<int> b(n);

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    std::vector<int> distances(n);

    // Calculate the distances for each cyclic shift
    for (int shift = 0; shift < n; shift++) {
        int min_dist = n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i] == b[(j + shift) % n]) {
                    min_dist = std::min(min_dist, std::abs(i - j));
                }
            }
        }
        distances[shift] = min_dist;
    }

    // Output the distances for each cyclic shift
    for (int i = 0; i < n; i++) {
        std::cout << distances[i] << std::endl;
    }

    return 0;
}