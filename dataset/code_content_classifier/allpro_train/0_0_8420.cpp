#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    if (N == 1) {
        std::cout << -1 << std::endl;
        return 0;
    }

    std::vector<std::vector<int>> board(N, std::vector<int>(N, 0));

    int num = 1;
    bool flag = true;

    for (int i = 0; i < N; i++) {
        if (flag) {
            for (int j = 0; j < N; j++) {
                if (j % 2 == 0) {
                    board[j][i] = num++;
                } else {
                    board[N-1-j][i] = num++;
                }
            }
            flag = false;
        } else {
            for (int j = N-1; j >= 0; j--) {
                if (j % 2 == 0) {
                    board[j][i] = num++;
                } else {
                    board[N-1-j][i] = num++;
                }
            }
            flag = true;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}