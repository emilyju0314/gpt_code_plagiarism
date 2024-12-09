#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        string s;
        cin >> s;

        int minRow = n, maxRow = 1, minCol = m, maxCol = 1;

        int curRow = 1, curCol = 1;
        for(char c : s) {
            if(c == 'L') {
                curCol--;
            } else if(c == 'R') {
                curCol++;
            } else if(c == 'U') {
                curRow--;
            } else if(c == 'D') {
                curRow++;
            }

            minRow = min(minRow, curRow);
            maxRow = max(maxRow, curRow);
            minCol = min(minCol, curCol);
            maxCol = max(maxCol, curCol);
        }

        cout << (minRow + maxRow) / 2 << " " << (minCol + maxCol) / 2 << endl;
    }

    return 0;
}