#include <iostream>
#include <cmath>

using namespace std;

int main() {
    char s_col, t_col;
    int s_row, t_row;

    cin >> s_col >> s_row;
    cin >> t_col >> t_row;

    int num_moves = max(abs(s_col - t_col), abs(s_row - t_row));

    cout << num_moves << endl;

    // Print moves
    for (int i = 0; i < num_moves; i++) {
        if (s_col < t_col) {
            cout << "R";
            s_col++;
        } else if (s_col > t_col) {
            cout << "L";
            s_col--;
        }

        if (s_row < t_row) {
            cout << "U";
            s_row++;
        } else if (s_row > t_row) {
            cout << "D";
            s_row--;
        }

        cout << endl;
    }

    return 0;
}