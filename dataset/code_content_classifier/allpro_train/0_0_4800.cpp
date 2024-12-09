#include <iostream>
using namespace std;

bool isEvenAdjacentCells(char board[][100], int n) {
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int count = 0;
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x >= 0 && x < n && y >= 0 && y < n && board[x][y] == 'o') {
                    count++;
                }
            }
            if (count % 2 != 0) {
                return false;
            }
        }
    }
    
    return true;
}

int main() {
    int n;
    cin >> n;
    
    char board[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    
    if (isEvenAdjacentCells(board, n)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}