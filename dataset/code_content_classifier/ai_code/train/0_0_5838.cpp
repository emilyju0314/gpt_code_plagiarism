#include <iostream>
#include <vector>
#include <algorithm>

int n, m;
std::vector<std::vector<int>> initial_board, target_board;
std::vector<std::pair<int, int>> result_moves;
std::vector<std::vector<int>> visited;

bool is_valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool dfs(int x, int y, int moves) {
    if (moves > 1) return false;

    visited[x][y] = 1;

    if (x > 0 && !visited[x - 1][y]) {
        std::swap(initial_board[x][y], initial_board[x - 1][y]);
        result_moves.push_back({x, y});
        if (initial_board == target_board) return true;
        if (dfs(x - 1, y, moves + 1)) return true;
        std::swap(initial_board[x][y], initial_board[x - 1][y]);
        result_moves.pop_back();
    }

    if (x < n - 1 && !visited[x + 1][y]) {
        std::swap(initial_board[x][y], initial_board[x + 1][y]);
        result_moves.push_back({x, y});
        if (initial_board == target_board) return true;
        if (dfs(x + 1, y, moves + 1)) return true;
        std::swap(initial_board[x][y], initial_board[x + 1][y]);
        result_moves.pop_back();
    }

    if (y > 0 && !visited[x][y - 1]) {
        std::swap(initial_board[x][y], initial_board[x][y - 1]);
        result_moves.push_back({x, y});
        if (initial_board == target_board) return true;
        if (dfs(x, y - 1, moves + 1)) return true;
        std::swap(initial_board[x][y], initial_board[x][y - 1]);
        result_moves.pop_back();
    }

    if (y < m - 1 && !visited[x][y + 1]) {
        std::swap(initial_board[x][y], initial_board[x][y + 1]);
        result_moves.push_back({x, y});
        if (initial_board == target_board) return true;
        if (dfs(x, y + 1, moves + 1)) return true;
        std::swap(initial_board[x][y], initial_board[x][y + 1]);
        result_moves.pop_back();
    }

    visited[x][y] = 0;
    return false;
}

int main() {
    std::cin >> n >> m;

    initial_board.resize(n, std::vector<int>(m));
    visited.resize(n, std::vector<int>(m, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> initial_board[i][j];
        }
    }
    
    target_board.resize(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> target_board[i][j];
        }
    }

    if (initial_board == target_board) {
        std::cout << 0 << std::endl;
    } else {
        if (dfs(0, 0, 0)) {
            std::reverse(result_moves.begin(), result_moves.end());
            std::cout << result_moves.size() << std::endl;
            std::cout << result_moves[0].first + 1 << " " << result_moves[0].second + 1 << std::endl;
            for (int i = 1; i < result_moves.size(); i++) {
                std::cout << result_moves[i].first + 1 << " " << result_moves[i].second + 1 << std::endl;
            }
        } else {
            std::cout << -1 << std::endl;
        }
    }

    return 0;
}