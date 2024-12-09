#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> board(n);
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    vector<int> required(m);
    for (int i = 0; i < m; i++) {
        cin >> required[i];
    }

    int operations = 0;
    for (int col = 0; col < m; col++) {
        vector<bool> disturbed(n, false);
        int cnt = 0;
        for (int row = n - 1; row >= 0; row--) {
            if (board[row][col] == '#' && !disturbed[row]) {
                cnt++;
                disturbed[row] = true;
                if (cnt == required[col]) {
                    break;
                }
                for (int r = row - 1; r >= 0; r--) {
                    if (board[r][col] == '#') {
                        disturbed[r] = true;
                    } else {
                        break;
                    }
                }
            }
        }
        operations = max(operations, cnt);
    }

    cout << operations << endl;

    return 0;
}