#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
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

        int diff = b[0] - a[0];
        bool possible = true;

        for (int i = 1; i < n; i++) {
            int curr_diff = b[i] - a[i];

            if (diff == 0) {
                if (curr_diff != 0) {
                    possible = false;
                    break;
                }
            } else {
                if (curr_diff == 0 || curr_diff % diff != 0) {
                    possible = false;
                    break;
                }
            }
        }

        if (possible) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}