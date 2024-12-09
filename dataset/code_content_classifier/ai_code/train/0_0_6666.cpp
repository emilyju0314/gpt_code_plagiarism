#include <iostream>
#include <queue>
#include <unordered_set>
#include <string>
#include <sstream>

using namespace std;

struct State {
    vector<vector<int>> board;
    int zero_row, zero_col;
    int steps;

    bool operator==(const State& other) const {
        return board == other.board;
    }

    size_t hash() const {
        size_t result = 17;
        for (const auto& row : board) {
            for (int val : row) {
                result = result * 31 + size_t(val);
            }
        }
        return result;
    }
};

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int solvePuzzle(const State& start) {
    queue<State> q;
    unordered_set<size_t> visited;

    q.push(start);
    visited.insert(start.hash());

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        if (current.board == vector<vector<int>>{{1, 2, 3}, {4, 5, 6}, {7, 8, 0}}) {
            return current.steps;
        }

        for (int i = 0; i < 4; i++) {
            int next_zero_row = current.zero_row + dx[i];
            int next_zero_col = current.zero_col + dy[i];

            if (next_zero_row >= 0 && next_zero_row < 3 && next_zero_col >= 0 && next_zero_col < 3) {
                State next = current;
                swap(next.board[current.zero_row][current.zero_col], next.board[next_zero_row][next_zero_col]);
                next.zero_row = next_zero_row;
                next.zero_col = next_zero_col;
                next.steps++;

                if (visited.find(next.hash()) == visited.end()) {
                    q.push(next);
                    visited.insert(next.hash());
                }
            }
        }
    }

    return -1; // No solution found
}

int main() {
    State start;
    start.board.resize(3, vector<int>(3));
    start.steps = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> start.board[i][j];
            if (start.board[i][j] == 0) {
                start.zero_row = i;
                start.zero_col = j;
            }
        }
    }

    int min_steps = solvePuzzle(start);
    cout << min_steps << endl;

    return 0;
}