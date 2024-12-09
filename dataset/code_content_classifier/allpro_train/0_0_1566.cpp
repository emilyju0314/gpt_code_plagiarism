#include <iostream>
#include <set>

int main() {
    int q;
    std::cin >> q;

    std::set<int> eels;
    int danger = 0;

    for (int i = 0; i < q; i++) {
        char op;
        int x;
        std::cin >> op >> x;

        if (op == '+') {
            eels.insert(x);
            auto it = eels.lower_bound(x);
            auto next_it = std::next(it);
            if (next_it != eels.end() && *next_it <= 2 * x) {
                danger++;
            }
            if (it != eels.begin() && x <= 2 * *std::prev(it)) {
                danger++;
            }
        } else {
            auto it = eels.lower_bound(x);
            auto next_it = std::next(it);
            if (next_it != eels.end() && *next_it <= 2 * x) {
                danger--;
            }
            if (it != eels.begin() && x <= 2 * *std::prev(it)) {
                danger--;
            }
            eels.erase(x);
        }

        std::cout << danger << std::endl;
    }

    return 0;
}