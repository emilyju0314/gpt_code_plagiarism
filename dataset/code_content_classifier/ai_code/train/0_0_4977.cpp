#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int row, int col, vector<string>& field) {
    if(row < 0 || row >= 3 || col >= field[0].size() || field[row][col] != '.') {
        return false;
    }
    return true;
}

bool canWin(int n, int k, vector<string>& field) {
    int currRow = 0;
    int currCol = 0;

    for(int i = 0; i < n; i++) {
        if(field[0][i] == 's') {
            currCol = i;
            break;
        }
    }

    while(currCol < n - 1) {
        // Try going right
        currCol++;
        
        // Try going up
        if(isSafe(currRow-1, currCol, field)) {
            currRow--;
        } 
        // Try going down
        else if(isSafe(currRow+1, currCol, field)) {
            currRow++;
        }
        
        if(field[currRow][currCol] != '.' && field[currRow][currCol] != 's') {
            return false;
        }

        // Move trains
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 3; j++) {
                if(field[j][i] != '.' && field[j][i] != 's') {
                    if(i == 0) {
                        field[j][i] = '.';
                    } else {
                        field[j][i-1] = field[j][i];
                        field[j][i] = '.';
                    }
                }
            }
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<string> field(3);
        for(int i = 0; i < 3; i++) {
            cin >> field[i];
        }

        if(canWin(n, k, field)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}