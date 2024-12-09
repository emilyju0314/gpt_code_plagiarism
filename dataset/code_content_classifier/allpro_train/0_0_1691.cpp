#include <iostream>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> boys(n);
    for (int i = 0; i < n; i++) {
        boys[i] = i + 1;
    }

    int offset = 0;
    bool swap_boys = false;
    for (int i = 0; i < q; i++) {
        int type, x;
        std::cin >> type;
        if (type == 1) {
            std::cin >> x;
            offset = (offset + x + n) % n;
        } else {
            swap_boys = !swap_boys;
        }
    }

    if (swap_boys) {
        for (int i = 0; i < n; i += 2) {
            std::swap(boys[i], boys[i + 1]);
        }
    }

    std::vector<int> final_positions(n);
    for (int i = 0; i < n; i++) {
        final_positions[boys[i] - 1] = (i + offset) % n + 1;
    }

    for (int i = 0; i < n; i++) {
        std::cout << final_positions[i] << " ";
    }

    return 0;
}