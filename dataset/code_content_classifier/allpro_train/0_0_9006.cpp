#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> A(n);
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    int q;
    std::cin >> q;

    for (int i = 0; i < q; i++) {
        int k;
        std::cin >> k;

        auto it = std::lower_bound(A.begin(), A.end(), k);
        int lb = std::distance(A.begin(), it);

        std::cout << lb << "\n";
    }

    return 0;
}