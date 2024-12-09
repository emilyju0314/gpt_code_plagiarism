#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int X, Y;
vector<vector<char>> grid;

void changeColor(int x, int y, char prevColor, char newColor) {
    if (x < 0 || x >= X || y < 0 || y >= Y || grid[y][x] != prevColor) {
        return;
    }
    grid[y][x] = newColor;
    changeColor(x+1, y, prevColor, newColor);
    changeColor(x-1, y, prevColor, newColor);
    changeColor(x, y+1, prevColor, newColor);
    changeColor(x, y-1, prevColor, newColor);
}

int countOperations() {
    int count = 0;
    while (true) {
        char targetColor = grid[0][0];
        if (targetColor == ' ') {
            break;
        }
        changeColor(0, 0, targetColor, ' ');
        count++;
    }
    return count;
}

int main() {
    while (true) {
        cin >> X >> Y;
        if (X == 0 && Y == 0) {
            break;
        }
        
        grid.clear();
        grid.resize(Y, vector<char>(X));
        
        for (int i = 0; i < Y; i++) {
            for (int j = 0; j < X; j++) {
                cin >> grid[i][j];
            }
        }
        
        int operations = countOperations();
        cout << operations << endl;
    }
    
    return 0;
}