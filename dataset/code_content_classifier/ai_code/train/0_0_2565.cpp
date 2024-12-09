#include <iostream>

using namespace std;

int main() {
    char board[8][8];

    // Input the client's requirements
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> board[i][j];
        }
    }

    int rows = 0;
    int cols = 0;

    // Count the number of rows that need to be painted
    for (int i = 0; i < 8; i++) {
        bool need_paint = false;
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 'B') {
                need_paint = true;
                break;
            }
        }
        if (need_paint) rows++;
    }

    // Count the number of columns that need to be painted
    for (int j = 0; j < 8; j++) {
        bool need_paint = false;
        for (int i = 0; i < 8; i++) {
            if (board[i][j] == 'B') {
                need_paint = true;
                break;
            }
        }
        if (need_paint) cols++;
    }

    // Output the minimum number of strokes required
    cout << min(rows, cols) << endl;

    return 0;
}