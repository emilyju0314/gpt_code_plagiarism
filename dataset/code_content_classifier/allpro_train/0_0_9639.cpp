#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, m;
        std::cin >> n >> m;

        std::vector<int> bottom_trains(n);
        std::vector<int> left_trains(m);

        for (int i = 0; i < n; i++) {
            std::cin >> bottom_trains[i];
        }

        for (int i = 0; i < m; i++) {
            std::cin >> left_trains[i];
        }

        std::sort(bottom_trains.begin(), bottom_trains.end());
        std::sort(left_trains.begin(), left_trains.end());

        int cancel_count = 0;
        for (int i = 0; i < n; i++) {
            if (std::binary_search(left_trains.begin(), left_trains.end(), bottom_trains[i])) {
                cancel_count++;
            }
        }

        std::cout << cancel_count << std::endl;
    }

    return 0;
}