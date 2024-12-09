#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        char grid[9][9];
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                cin >> grid[i][j];
                // Change the first element in each row to create anti-sudoku
                if(j == 0) {
                    if(grid[i][j] != '1') {
                        grid[i][j] = '1';
                    } else {
                        grid[i][j] = '2';
                    }
                }
            }
        }

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}