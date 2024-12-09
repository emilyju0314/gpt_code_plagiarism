#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> board(n, vector<int>(m, 0));
    vector<vector<int>> count(n, vector<int>(m, 0));

    int x;
    cin >> x;

    for (int i = 0; i < x; i++) {
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (board[r][c] == 0) {
                    int adj_count = 0;
                    if (r > 0 && c > 0 && board[r-1][c-1] == i) adj_count++;
                    if (r > 0 && c < m-1 && board[r-1][c+1] == i) adj_count++;
                    if (r < n-1 && c > 0 && board[r+1][c-1] == i) adj_count++;
                    if (r < n-1 && c < m-1 && board[r+1][c+1] == i) adj_count++;

                    if (adj_count == 4) {
                        count[r][c]++;
                    }
                }
            }
        }

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (count[r][c] > 0) {
                    board[r][c] = i;
                }
            }
        }
    }

    int result = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (count[r][c] == x) {
                result++;
            }
        }
    }

    cout << result << endl;

    return 0;
}