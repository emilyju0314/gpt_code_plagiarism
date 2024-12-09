#include <iostream>
#include <vector>

using namespace std;

void printGrid(vector<string> grid) {
    for (string row : grid) {
        cout << row << endl;
    }
}

bool isAdjacent(char a, char b) {
    int dx = abs((a - 'A') % 13 - (b - 'A') % 13);
    int dy = abs((a - 'A') / 13 - (b - 'A') / 13);
    
    return (dx <= 1 && dy <= 1);
}

int main() {
    string s;
    cin >> s;

    vector<string> grid(2, string(13, '.'));

    for (int i = 0; i < 13; i++) {
        grid[0][i] = s[i];
    }

    grid[1][12] = s[13];

    for (int i = 14; i < 26; i++) {
        char currentChar = s[i];
        
        bool placed = false;
        
        for (int row = 0; row < 2; row++) {
            for (int col = 0; col < 13; col++) {
                if (grid[row][col] == '.') {
                    bool isValid = true;
                    if (row > 0) isValid = isValid && isAdjacent(grid[row - 1][col], currentChar);
                    if (col > 0) isValid = isValid && isAdjacent(grid[row][col - 1], currentChar);
                    if (isValid) {
                        grid[row][col] = currentChar;
                        placed = true;
                        break;
                    }
                }
            }
            if (placed) break;
        }
        
        if (!placed) {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    printGrid(grid);

    return 0;
}