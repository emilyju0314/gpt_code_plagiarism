#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            std::cin >> b[i];
        }

        int min_a = *std::min_element(a.begin(), a.end());
        int min_b = *std::min_element(b.begin(), b.end());

        bool possible = false;
        for (int i = 0; i < n; i++) {
            if (a[i] > min_a && b[i] > min_b) {
                possible = true;
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            if (a[i] == min_a && b[i] == min_b) {
                std::cout << (possible ? "1" : "0");
            } else {
                std::cout << "1";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}