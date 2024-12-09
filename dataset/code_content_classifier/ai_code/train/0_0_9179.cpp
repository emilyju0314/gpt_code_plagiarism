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
    for (int i = 0; i < q; i++) {
        int com, b, e;
        std::cin >> com >> b >> e;

        if (com == 0) {
            int min_val = *min_element(A.begin() + b, A.begin() + e);
            std::cout << min_val << std::endl;
        } else {
            int max_val = *max_element(A.begin() + b, A.begin() + e);
            std::cout << max_val << std::endl;
        }
    }

    return 0;
}