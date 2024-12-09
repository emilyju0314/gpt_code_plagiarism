#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n;
    std::vector<int> A(n);

    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    std::cin >> m;
    std::vector<int> B(m);

    for (int i = 0; i < m; i++) {
        std::cin >> B[i];
    }

    int a, b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (std::find(A.begin(), A.end(), A[i] + B[j]) == A.end() &&
                std::find(B.begin(), B.end(), A[i] + B[j]) == B.end()) {
                a = A[i];
                b = B[j];
                break;
            }
        }
    }

    std::cout << a << " " << b << std::endl;

    return 0;
}