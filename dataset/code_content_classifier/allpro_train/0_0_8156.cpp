#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n_r, n_g, n_b;
        std::cin >> n_r >> n_g >> n_b;

        std::vector<long long> red(n_r), green(n_g), blue(n_b);
        for (int i = 0; i < n_r; i++) {
            std::cin >> red[i];
        }
        for (int i = 0; i < n_g; i++) {
            std::cin >> green[i];
        }
        for (int i = 0; i < n_b; i++) {
            std::cin >> blue[i];
        }

        std::sort(red.begin(), red.end());
        std::sort(green.begin(), green.end());
        std::sort(blue.begin(), blue.end());

        long long min_diff = LLONG_MAX;
        for (long long r : red) {
            auto g = std::lower_bound(green.begin(), green.end(), r);
            auto b = std::upper_bound(blue.begin(), blue.end(), r);
            if (g != green.end() && b != blue.begin()) {
                long long x = r, y = *g, z = *(--b);
                min_diff = std::min(min_diff, (x - y)*(x - y) + (y - z)*(y - z) + (z - x)*(z - x));
            }
        }

        std::cout << min_diff << std::endl;
    }

    return 0;
}