#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> magicFigure = {
    {0,0}, {0,1}, {1,1}, {1,0}
};

bool isValid(vector<vector<int>>& board, int x, int y) {
    for(auto& cell : magicFigure) {
        int newX = x + cell[0];
        int newY = y + cell[1];
        if(newX < 0 || newX >= board.size() || newY < 0 || newY >= board[0].size() || board[newX][newY] == -1) {
            return false;
        }
    }
    return true;
}

void fillMagicFigure(vector<vector<int>>& board, int x, int y, int num) {
    for(auto& cell : magicFigure) {
        board[x + cell[0]][y + cell[1]] = num;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> board(n, vector<int>(m, -1));
    char chip = 'a';
    int numChips = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if(c != '.') {
                if(board[i][j] == -1) {
                    board[i][j] = numChips;
                    fillMagicFigure(board, i, j, numChips);
                    numChips++;
                }
            }
        }
    }

    int ways = 0;
    do {
        bool isMagic = true;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] != -1 && !isValid(board, i, j)) {
                    isMagic = false;
                    break;
                }
            }
            if(!isMagic) {
                break;
            }
        }

        if(isMagic) {
            ways++;
        }
    } while(next_permutation(magicFigure.begin(), magicFigure.end()));

    cout << ways << endl;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == -1) {
                cout << '.';
            } else {
                cout << board[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}