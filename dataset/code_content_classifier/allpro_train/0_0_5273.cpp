#include <iostream>
#include <vector>

const int N = 5;
int board[N][N];
int scores[6];
int bonus = 1;
int maxScore = 0;

void calculateMaxScore() {
    // Move blocks in all 4 directions
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i > 0) {
                std::swap(board[i][j], board[i - 1][j]);
                calculateMaxScore(); // Recursively check for other possible moves
                std::swap(board[i][j], board[i - 1][j]);
            }
            if (i < N - 1) {
                std::swap(board[i][j], board[i + 1][j]);
                calculateMaxScore();
                std::swap(board[i][j], board[i + 1][j]);
            }
            if (j > 0) {
                std::swap(board[i][j], board[i][j - 1]);
                calculateMaxScore();
                std::swap(board[i][j], board[i][j - 1]);
            }
            if (j < N - 1) {
                std::swap(board[i][j], board[i][j + 1]);
                calculateMaxScore();
                std::swap(board[i][j], board[i][j + 1]);
            }
        }
    }

    // Check and update scores after the blocks have fallen and matched
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) {
                for (int k = i - 1; k >= 0; k--) {
                    if (board[k][j] != 0) {
                        std::swap(board[i][j], board[k][j]);
                        break;
                    }
                }
            }
        }
    }

    // Calculate score after blocks have fallen
    int currentScore = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) break;
            currentScore += scores[board[i][j]] * bonus;
        }
    }

    maxScore = std::max(maxScore, currentScore);
}

int main() {
    int n;
    while (std::cin >> n && n != -1) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                std::cin >> board[i][j];
            }
        }
        for (int i = 1; i <= 5; i++) {
            std::cin >> scores[i];
        }

        maxScore = 0;
        calculateMaxScore();
        std::cout << maxScore << std::endl;
    }

    return 0;
}