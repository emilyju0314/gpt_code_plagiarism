#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int r, c;
    cin >> r >> c;

    vector<string> forest(r);
    int start_row, start_col, exit_row, exit_col;
    
    for (int i = 0; i < r; i++) {
        cin >> forest[i];
        if (forest[i].find('S') != string::npos) {
            start_row = i;
            start_col = forest[i].find('S');
        }
        if (forest[i].find('E') != string::npos) {
            exit_row = i;
            exit_col = forest[i].find('E');
        }
    }

    int battles = 0;
    for (int i = start_row; i <= exit_row; i++) {
        for (int j = 0; j < c; j++) {
            if (forest[i][j] != 'T' && (i != exit_row || j != exit_col)) {
                if (isdigit(forest[i][j])) {
                    battles += (forest[i][j] - '0');
                }
            }
        }
    }

    cout << battles << endl;

    return 0;
}