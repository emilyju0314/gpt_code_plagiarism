#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int matrix[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j< n; j++) {
            std::cin >> matrix[i][j];
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += matrix[i][i]; // main diagonal
        sum += matrix[i][n-i-1]; // secondary diagonal
        sum += matrix[n/2][i]; // middle row
        sum += matrix[i][n/2]; // middle column
    }

    // If the middle element is counted 4 times, subtract it once
    sum -= matrix[n/2][n/2];

    std::cout << sum << std::endl;

    return 0;
}