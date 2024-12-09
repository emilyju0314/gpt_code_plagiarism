#include <iostream>
#include <unordered_set>

int main() {
    int q;
    std::cin >> q;

    std::unordered_set<int> S;

    for (int i = 0; i < q; i++) {
        int operation, x;
        std::cin >> operation >> x;

        if (operation == 0) {
            S.insert(x);
            std::cout << S.size() << std::endl;
        } else {
            std::cout << S.count(x) << std::endl;
        }
    }

    return 0;
}