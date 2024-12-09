#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Point {
    int x, y;
};

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<vector<char>> board(n, vector<char>(n));
        vector<Point> tiles(26); // Assuming at most 26 different characters (A-Z)
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> board[i][j];
                if (isalpha(board[i][j])) {
                    tiles[board[i][j] - 'A'] = {i, j};
                }
            }
        }
        
        string seq;
        cin >> seq;
        
        Point dirs[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // U, D, L, R
        
        for (char c : seq) {
            if (c == '(') continue; // Skip '('
            
            if (c == ')') {
                // Handle repeated sequences
                int k = seq[seq.find(c) + 1] - '0';
                int i = seq.find(c) - 1;
                int j = seq.find_last_of('(') + 1;
                string subseq = seq.substr(j, i - j);
                
                string newSeq = "";
                for (int l = 0; l < k; l++) {
                    newSeq += subseq;
                }
                
                for (char subc : newSeq) {
                    int dx = dirs[subc - 'L'].x;
                    int dy = dirs[subc - 'L'].y;
                    
                    int x, y;
                    for (int i = 0; i < 26; i++) {
                        x = tiles[i].x + dx;
                        y = tiles[i].y + dy;
                        if (x >= 0 && x < n && y >= 0 && y < n) {
                            swap(board[tiles[i].x][tiles[i].y], board[x][y]);
                            tiles[i] = {x, y};
                        }
                    }
                }
                
                seq = seq.substr(0, j) + newSeq + seq.substr(i + 2);
            } else {
                int dx = dirs[c - 'L'].x;
                int dy = dirs[c - 'L'].y;
                
                int x, y;
                for (int i = 0; i < 26; i++) {
                    x = tiles[i].x + dx;
                    y = tiles[i].y + dy;
                    if (x >= 0 && x < n && y >= 0 && y < n) {
                        swap(board[tiles[i].x][tiles[i].y], board[x][y]);
                        tiles[i] = {x, y};
                    }
                }
            }
        }
        
        // Print the final board
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}