#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for (int i = 0; i < q; i++) {
        int t, x, y;
        std::cin >> t >> x >> y;

        if (t == 1) {
            a[x-1] = std::max(a[x-1], y);
        } else {
            int meals = 0;
            int money = y;
            for (int j = x-1; j < n; j++) {
                if (money >= a[j]) {
                    money -= a[j];
                    meals++;
                } else {
                    break;
                }
            }
            std::cout << meals << std::endl;
        }
    }

    return 0;
}