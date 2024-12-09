#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> board(n, vector<int>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    while (q--) {
        int op, x, y;
        cin >> op >> x >> y;

        if (op == 1) {
            board[x - 1][y - 1] = 1 - board[x - 1][y - 1];
        } else {
            int ans = 0;
            for (int i = x - 1; i < n; i++) {
                for (int j = y - 1; j < m; j++) {
                    if (board[i][j] == 0) break;
                    int area = (i - x + 2) * (j - y + 2);
                    ans = max(ans, area);
                }
            }
            cout << ans << endl;
        }
    }

    return 0;
}