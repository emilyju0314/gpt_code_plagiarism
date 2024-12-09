#include <iostream>
#include <vector>

int main() {
    int a, c;
    std::cin >> a >> c;

    std::vector<int> a_ternary, c_ternary, b_ternary;

    while (a > 0) {
        a_ternary.push_back(a % 3);
        a /= 3;
    }

    while (c > 0) {
        c_ternary.push_back(c % 3);
        c /= 3;
    }

    while (a_ternary.size() < c_ternary.size()) {
        a_ternary.push_back(0);
    }

    for (int i = 0; i < c_ternary.size(); i++) {
        int b = (c_ternary[i] - a_ternary[i] + 3) % 3;
        b_ternary.push_back(b);
    }

    for (int i = b_ternary.size() - 1; i >= 0; i--) {
        std::cout << b_ternary[i];
    }

    return 0;
}