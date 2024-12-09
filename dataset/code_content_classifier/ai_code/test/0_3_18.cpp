#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, d;
        std::cin >> n >> d;
        std::vector<int> a(n);

        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        std::vector<int> initial = a;
        int steps = 0;

        while (true) {
            std::vector<int> new_a(n);
            for (int i = 0; i < n; i++) {
                new_a[i] = a[(i + n - d) % n] & a[i];
            }
            steps++;

            if (new_a == a) {
                break;
            }

            a = new_a;

            if (std::all_of(a.begin(), a.end(), [](int x) { return x == 0; })) {
                break;
            }
        }

        if (std::all_of(a.begin(), a.end(), [](int x) { return x == 0; })) {
            std::cout << steps << std::endl;
        } else {
            std::cout << -1 << std::endl;
        }
    }

    return 0;
}