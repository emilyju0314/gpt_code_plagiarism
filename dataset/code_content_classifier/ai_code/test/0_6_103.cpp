#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 2005;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;
        char board[MAXN][MAXN];
        vector<vector<int>> steps(n, vector<int>(m, -1));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> board[i][j];
            }
        }

        int max_steps = 0;
        int start_r = 0, start_c = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(steps[i][j] != -1) continue;

                int r = i, c = j;
                int cur_steps = 0;
                vector<vector<bool>> visited(n, vector<bool>(m, false));

                while(r >= 0 && r < n && c >= 0 && c < m && !visited[r][c]) {
                    visited[r][c] = true;
                    steps[r][c] = cur_steps;

                    if(board[r][c] == 'L') c--;
                    else if(board[r][c] == 'R') c++;
                    else if(board[r][c] == 'D') r++;
                    else if(board[r][c] == 'U') r--;

                    cur_steps++;
                }

                if(cur_steps > max_steps) {
                    max_steps = cur_steps;
                    start_r = i+1;
                    start_c = j+1;
                }
            }
        }
        cout << start_r << " " << start_c << " " << max_steps << endl;
    }
    return 0;
}