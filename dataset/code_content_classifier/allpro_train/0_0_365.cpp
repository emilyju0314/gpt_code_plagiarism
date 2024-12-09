#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> board(n, std::vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            std::cin >> board[i][j];
        }
    }

    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int sum_row = 0, sum_col = 0;
            for(int k = 0; k < n; k++) {
                sum_row += board[i][k];
                sum_col += board[k][j];
            }
            if(sum_col > sum_row) {
                count++;
            }
        }
    }

    std::cout << count << std::endl;

    return 0;
}