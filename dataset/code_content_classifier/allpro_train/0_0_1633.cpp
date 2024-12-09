#include <iostream>
#include <vector>

void displayRoundPattern(int n) {
    std::vector<std::vector<char>> pattern(n, std::vector<char>(n, ' '));

    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    char symbol = '#';
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; ++i) {
            pattern[bottom][i] = symbol;
        }
        --bottom;

        for (int i = bottom; i >= top; --i) {
            pattern[i][right] = symbol;
        }
        --right;

        for (int i = right; i >= left; --i) {
            pattern[top][i] = symbol;
        }
        ++top;

        for (int i = top; i <= bottom; ++i) {
            pattern[i][left] = symbol;
        }
        ++left;

        symbol = (symbol == '#') ? ' ' : '#';
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << pattern[i][j];
        }
        std::cout << std::endl;
    }
}

int main() {
    int d;
    std::cin >> d;

    for (int i = 0; i < d; ++i) {
        int n;
        std::cin >> n;
        displayRoundPattern(n);
        if (i < d - 1) {
            std::cout << std::endl;
        }
    }

    return 0;
}