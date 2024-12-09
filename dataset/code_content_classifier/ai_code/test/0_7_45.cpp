#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> days(n);
        for (int i = 0; i < n; i++) {
            std::cin >> days[i];
        }

        int height = 1;
        bool dead = false;
        int last_watered = 0;

        for (int i = 0; i < n; i++) {
            if (days[i] == 1) {
                if (i - last_watered == 1) {
                    height += 5;
                } else {
                    height += 1;
                }
                last_watered = i;
            } else {
                if (i - last_watered == 2) {
                    dead = true;
                    break;
                }
            }
        }

        if (dead) {
            std::cout << -1 << std::endl;
        } else {
            std::cout << height << std::endl;
        }
    }

    return 0;
}