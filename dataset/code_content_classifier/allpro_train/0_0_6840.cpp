#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, q;
    std::cin >> n;

    std::vector<int> A(n);
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    std::cin >> q;
    while (q--) {
        int b, e;
        std::cin >> b >> e;

        std::reverse(A.begin() + b, A.begin() + e);
    }

    for (int i = 0; i < n; i++) {
        std::cout << A[i];
        if (i < n - 1) {
            std::cout << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}