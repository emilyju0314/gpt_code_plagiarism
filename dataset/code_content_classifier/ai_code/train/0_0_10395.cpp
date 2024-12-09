#include <iostream>
#include <vector>

int main() {
    int n, m, l;
    std::cin >> n >> m >> l;

    std::vector<std::vector<int>> A(n, std::vector<int>(m));
    std::vector<std::vector<int>> B(m, std::vector<int>(l));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> A[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < l; j++) {
            std::cin >> B[i][j];
        }
    }

    std::vector<std::vector<int>> C(n, std::vector<int>(l, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++) {
            for (int k = 0; k < m; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++) {
            std::cout << C[i][j];
            if (j < l - 1) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}