#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }

    int t;
    std::cin >> t;

    std::vector<bool> isNegative(n, false);
    for (int i = 0; i < t; i++) {
        int q;
        std::cin >> q;
        isNegative[q - 1] = true;
    }

    std::vector<int> x(n);
    std::vector<int> brackets;

    for (int i = 0; i < n; i++) {
        if (isNegative[i]) {
            x[i] = -p[i];
            brackets.push_back(p[i]);
        } else {
            x[i] = p[i];
            if (!brackets.empty()) {
                brackets.pop_back();
            } else {
                std::cout << "NO" << std::endl;
                return 0;
            }
        }
    }

    if (brackets.empty()) {
        std::cout << "YES" << std::endl;
        for (int i = 0; i < n; i++) {
            std::cout << x[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}