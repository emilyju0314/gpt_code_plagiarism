#include <iostream>
#include <unordered_set>

int main() {
    int q;
    std::cin >> q;

    std::unordered_set<int> S;
    for (int i = 0; i < q; i++) {
        int op, x;
        std::cin >> op >> x;
        if (op == 0) {
            S.insert(x);
            std::cout << S.size() << std::endl;
        } else if (op == 1) {
            std::cout << S.count(x) << std::endl;
        }
    }
}

