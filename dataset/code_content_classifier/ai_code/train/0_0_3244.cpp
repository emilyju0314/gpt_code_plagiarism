#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::vector<bool>> board(n, std::vector<bool>(m, false));
    for (int i = 0; i < k; ++i) {
        int x, y;
        std::cin >> x >> y;
        board[x-1][y-1] = true;
    }

    bool canWin = false;
    for (int i = 0; i < n; ++i) {
        if (board[i][0] || board[i][m-1]) {
            canWin = true;
            break;
        }
    }

    for (int j = 0; j < m; ++j) {
        if (board[0][j] || board[n-1][j]) {
            canWin = true;
            break;
        }
    }

    std::cout << (canWin ? "YES" : "NO") << std::endl;

    return 0;
}