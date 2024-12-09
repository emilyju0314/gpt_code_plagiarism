#include <iostream>
#include <vector>

int count(std::vector<int>& A, int b, int e, int k) {
    int count = 0;
    for (int i = b; i < e; i++) {
        if (A[i] == k) {
            count++;
        }
    }
    return count;
}

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
        int b, e, k;
        std::cin >> b >> e >> k;
        std::cout << count(A, b, e, k) << std::endl;
    }

    return 0;
}