#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;

        string s;
        cin >> s;

        int minRow = n, maxRow = 1, minCol = m, maxCol = 1;
        int curRow = 1, curCol = 1;

        for(char c : s) {
            if(c == 'U') {
                curRow--;
            } else if(c == 'D') {
                curRow++;
            } else if(c == 'L') {
                curCol--;
            } else {
                curCol++;
            }

            minRow = min(minRow, curRow);
            maxRow = max(maxRow, curRow);
            minCol = min(minCol, curCol);
            maxCol = max(maxCol, curCol);
        }

        int startRow = (minRow + maxRow) / 2;
        int startCol = (minCol + maxCol) / 2;

        cout << startRow << " " << startCol << endl;
    }

    return 0;
}