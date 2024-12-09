#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> A(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> A[i][j];
        }
    }

    int q;
    std::cin >> q;

    std::vector<int> result;
    int unusual_square = 0;

    for (int i = 0; i < q; i++) {
        int query_type, idx;
        std::cin >> query_type;

        if (query_type == 1 || query_type == 2) {
            std::cin >> idx;
            if (query_type == 1) {
                for (int j = 0; j < n; j++) {
                    A[idx-1][j] = 1 - A[idx-1][j];
                }
            } else {
                for (int j = 0; j < n; j++) {
                    A[j][idx-1] = 1 - A[j][idx-1];
                }
            }
        } else {
            unusual_square = 0;
            for (int j = 0; j < n; j++) {
                int dot_product = 0;
                for (int k = 0; k < n; k++) {
                    dot_product += A[j][k] * A[k][j];
                }
                unusual_square += dot_product % 2;
            }
            result.push_back(unusual_square);
        }
    }

    for (int val : result) {
        std::cout << val;
    }

    return 0;
}