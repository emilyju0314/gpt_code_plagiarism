#include <iostream>
#include <vector>

void createMagicSquare(int n) {
    std::vector<std::vector<int>> square(n, std::vector<int>(n, 0));

    int row = n - 1;
    int col = n / 2;
    for(int num = 1; num <= n * n; num++) {
        square[row][col] = num;
        row = (row + 1) % n;
        col = (col + 1) % n;

        if(square[row][col] != 0) {
            row = (row - 1 + n) % n;
            col = (col - 1 + n) % n;
            row = (row - 1 + n) % n;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            std::cout << std::right << std::setw(4) << square[i][j];
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;
    while(std::cin >> n && n != 0) {
        createMagicSquare(n);
        std::cout << std::endl;
    }
    return 0;
}