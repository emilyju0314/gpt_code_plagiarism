#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> board(n);
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    bool possible = true;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (board[i][j] == '#' && board[i-1][j] == '#' && board[i+1][j] == '#' && 
                board[i][j-1] == '#' && board[i][j+1] == '#') {
                board[i][j] = board[i-1][j] = board[i+1][j] = board[i][j-1] = board[i][j+1] = '.';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '#') {
                possible = false;
                break;
            }
        }
        if (!possible) {
            break;
        }
    }

    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}