#include <iostream>

int main() {
    int T;
    std::cin >> T;

    for (int i = 0; i < T; i++) {
        long long A, B, C, D;
        std::cin >> A >> B >> C >> D;

        if (B > A) {
            std::cout << "No" << std::endl;
            continue;
        }

        if (B > D) {
            std::cout << "No" << std::endl;
            continue;
        }

        long long diff = A - B;
        if (diff % B == 0) {
            std::cout << "Yes" << std::endl;
            continue;
        }

        long long max_possible_amount = B * (diff / B) + D;
        if (max_possible_amount >= B) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }

    return 0;
}