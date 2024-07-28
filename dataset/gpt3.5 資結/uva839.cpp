#include <iostream>

bool balance(int& w) {
    int w1, d1, w2, d2;
    bool b1 = true, b2 = true;

    std::cin >> w1 >> d1 >> w2 >> d2;

    if (!w1) {
        b1 = balance(w1);
    }
    if (!w2) {
        b2 = balance(w2);
    }

    w = w1 + w2;

    return b1 && b2 && (w1 * d1 == w2 * d2);
}

int main() {
    int T, W;

    std::cin >> T;

    while (T--) {
        if (balance(W)) {
            std::cout << "YES" << std::endl;
        }
        else {
            std::cout << "NO" << std::endl;
        }

        if (T) {
            std::cout << std::endl;
        }
    }

    return 0;
}