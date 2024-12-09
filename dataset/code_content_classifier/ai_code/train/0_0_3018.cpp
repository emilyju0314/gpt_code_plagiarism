#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, C;

    while (true) {
        cin >> N >> C;
        if (N == 0 && C == 0) {
            break;
        }

        vector<vector<int>> board(N, vector<int>(N));
        int maxPoints = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= i; j++) {
                cin >> board[i][j];
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= i; j++) {
                if (board[i][j] == C) {
                    vector<vector<int>> visited(N, vector<int>(N));
                    vector<pair<int, int>> group;
                    int points = 0;

                    group.push_back({i, j});
                    visited[i][j] = 1;

                    while (!group.empty()) {
                        int row = group.back().first;
                        int col = group.back().second;
                        group.pop_back();

                        if (row > 0 && board[row - 1][col] == C && visited[row - 1][col] == 0) {
                            group.push_back({row - 1, col});
                            visited[row - 1][col] = 1;
                        }
                        if (col > 0 && board[row][col - 1] == C && visited[row][col - 1] == 0) {
                            group.push_back({row, col - 1});
                            visited[row][col - 1] = 1;
                        }
                        if (row < N - 1 && board[row + 1][col] == C && visited[row + 1][col] == 0) {
                            group.push_back({row + 1, col});
                            visited[row + 1][col] = 1;
                        }
                        if (col < i && board[row][col + 1] == C && visited[row][col + 1] == 0) {
                            group.push_back({row, col + 1});
                            visited[row][col + 1] = 1;
                        }

                        points++;
                        board[row][col] = 0;
                    }

                    maxPoints = max(maxPoints, points);
                }
            }
        }

        cout << maxPoints << endl;
    }

    return 0;
}