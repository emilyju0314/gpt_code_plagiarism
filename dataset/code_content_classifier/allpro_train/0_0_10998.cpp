#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> A(n, std::vector<int>(m));
    std::vector<int> b(m);

    // Input matrix A
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            std::cin >> A[i][j];
        }
    }

    // Input vector b
    for(int i=0; i<m; i++) {
        std::cin >> b[i];
    }

    // Calculate the product Ab
    std::vector<int> c(n);
    for(int i=0; i<n; i++) {
        c[i] = 0;
        for(int j=0; j<m; j++) {
            c[i] += A[i][j] * b[j];
        }
    }

    // Output the result
    for(int i=0; i<n; i++) {
        std::cout << c[i] << std::endl;
    }

    return 0;
}