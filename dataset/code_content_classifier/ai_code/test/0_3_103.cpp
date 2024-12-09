#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> board(n, vector<char>(m));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> board[i][j];
            }
        }

        int max_moves = 0;
        int start_row = 0, start_col = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int cur_row = i, cur_col = j;
                int moves = 0;
                vector<vector<bool>> visited(n, vector<bool>(m, false));

                while(cur_row >= 0 && cur_row < n && cur_col >= 0 && cur_col < m && !visited[cur_row][cur_col]) {
                    visited[cur_row][cur_col] = true;
                    moves++;

                    switch(board[cur_row][cur_col]) {
                        case 'U':
                            cur_row--;
                            break;
                        case 'D':
                            cur_row++;
                            break;
                        case 'L':
                            cur_col--;
                            break;
                        case 'R':
                            cur_col++;
                            break;
                    }
                }

                if(moves > max_moves) {
                    max_moves = moves;
                    start_row = i + 1;
                    start_col = j + 1;
                }
            }
        }

        cout << start_row << " " << start_col << " " << max_moves << endl;
    }

    return 0;
}