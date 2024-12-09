#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

const int MOD = 10007;

int N, K;
std::vector<std::vector<bool>> grid;
int count = 0;

bool checkBingo(const std::vector<std::vector<bool>>& pattern) {
    // Check rows
    for (int i = 0; i < N; i++) {
        bool bingo = true;
        for (int j = 0; j < N; j++) {
            if (!pattern[i][j]) {
                bingo = false;
                break;
            }
        }
        if (bingo) return true;
    }

    // Check columns
    for (int j = 0; j < N; j++) {
        bool bingo = true;
        for (int i = 0; i < N; i++) {
            if (!pattern[i][j]) {
                bingo = false;
                break;
            }
        }
        if (bingo) return true;
    }

    // Check diagonals
    bool bingo1 = true, bingo2 = true;
    for (int i = 0; i < N; i++) {
        if (!pattern[i][i]) bingo1 = false;
        if (!pattern[i][N - 1 - i]) bingo2 = false;
    }

    return bingo1 || bingo2;
}

void generatePatterns(int unmarked, std::vector<std::vector<bool>>& pattern) {
    if (unmarked == 0) {
        if (!checkBingo(pattern)) {
            count++;
            count %= MOD;
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!pattern[i][j]) {
                pattern[i][j] = true;
                generatePatterns(unmarked - 1, pattern);
                pattern[i][j] = false;
            }
        }
    }
}

int main() {
    std::cin >> N >> K;

    grid.resize(N, std::vector<bool>(N, false));

    for (int i = 0; i < K; i++) {
        int x, y;
        std::cin >> x >> y;
        grid[x][y] = true;
    }

    generatePatterns(N * N - K, grid);

    std::cout << count << std::endl;

    return 0;
}