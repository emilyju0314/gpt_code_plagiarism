#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> W(n, std::vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            std::cin >> W[i][j];
        }
    }

    std::vector<std::vector<double>> A(n, std::vector<double>(n));
    std::vector<std::vector<double>> B(n, std::vector<double>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            A[i][j] = (W[i][j] + W[j][i]) / 2.0;
            B[i][j] = (W[i][j] - W[j][i]) / 2.0;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            std::cout << A[i][j] << " ";
        }
        std::cout << "\n";
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            std::cout << B[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}