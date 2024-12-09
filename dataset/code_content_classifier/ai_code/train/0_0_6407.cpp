#include <iostream>
#include <list>

int main() {
    int q;
    std::cin >> q;

    std::list<int> L;
    auto cursor = L.end();

    for (int i = 0; i < q; i++) {
        int op;
        std::cin >> op;

        if (op == 0) {
            int x;
            std::cin >> x;
            cursor = L.insert(cursor, x);
        } else if (op == 1) {
            int d;
            std::cin >> d;
            if (d > 0) {
                for (int j = 0; j < d; j++) {
                    cursor++;
                }
            } else {
                for (int j = 0; j > d; j--) {
                    cursor--;
                }
            }
        } else if (op == 2) {
            auto eraseIt = cursor;
            if (++eraseIt == L.end()) {
                cursor = L.erase(cursor);
            } else {
                L.erase(cursor);
                cursor = eraseIt;
            }
        }
    }

    for (auto it = L.begin(); it != L.end(); it++) {
        std::cout << *it << std::endl;
    }

    return 0;
}