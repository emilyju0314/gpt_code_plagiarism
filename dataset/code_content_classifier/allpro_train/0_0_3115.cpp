#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<string>> tetrominoes;

bool canFit(vector<string>& board, int row, int col, int tetrominoIdx) {
    vector<string>& tetromino = tetrominoes[tetrominoIdx];
    
    // Check if tetromino can fit on the board starting from row, col
    for (int i = 0; i < tetromino.size(); i++) {
        for (int j = 0; j < tetromino[i].size(); j++) {
            if (tetromino[i][j] == '#' && (row + i >= board.size() || col + j >= board[row + i].size() || board[row + i][col + j] != '.')) {
                return false; // Tetromino overlaps with existing block on the board or goes out of bounds
            }
        }
    }
    
    return true;
}

bool coverBoard(vector<string>& board) {
    // Try all combinations of tetrominoes on the board
    for (int i = 0; i < tetrominoes.size(); i++) {
        for (int j = 0; j < tetrominoes.size(); j++) {
            for (int k = 0; k < tetrominoes.size(); k++) {
                if (i == j || i == k || j == k) continue;
                
                bool success = false;
                
                for (int row = 0; row < board.size(); row++) {
                    for (int col = 0; col < board[row].size(); col++) {
                        if (canFit(board, row, col, i) && canFit(board, row, col + 2, j) && canFit(board, row + 1, col + 1, k)) {
                            success = true;
                            break;
                        }
                    }
                    
                    if (success) break;
                }
                
                if (!success) {
                    return false;
                }
            }
        }
    }
    
    return true;
}

int main() {
    int t1_h, t1_w, t2_h, t2_w, t3_h, t3_w, t4_h, t4_w, n;
    cin >> t1_h >> t1_w;
    vector<string> t1(t1_h);
    for (int i = 0; i < t1_h; i++) {
        cin >> t1[i];
    }
    
    cin >> t2_h >> t2_w;
    vector<string> t2(t2_h);
    for (int i = 0; i < t2_h; i++) {
        cin >> t2[i];
    }
    
    cin >> t3_h >> t3_w;
    vector<string> t3(t3_h);
    for (int i = 0; i < t3_h; i++) {
        cin >> t3[i];
    }
    
    cin >> t4_h >> t4_w;
    vector<string> t4(t4_h);
    for (int i = 0; i < t4_h; i++) {
        cin >> t4[i];
    }
    
    tetrominoes = {t1, t2, t3, t4};
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        vector<string> board(4, string(10, '.'));
        for (int j = 0; j < 4; j++) {
            string line;
            cin >> line;
            board[j] = line;
        }
        
        if (coverBoard(board)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}