#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<char>> chessboard(n, vector<char>(m));
    // Reading the chessboard
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> chessboard[i][j];
        }
    }
    
    // Checking if Ksenia can get infinitely many points
    bool infinite = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (chessboard[i][j] != '#' && chessboard[i][j] != '<' && chessboard[i][j] != '>' && chessboard[i][j] != '^' && chessboard[i][j] != 'v') {
                infinite = true;
            }
        }
    }
    
    if (infinite) {
        cout << -1 << endl;
    } else {
        int points = 0;
        // Counting the movements for each pawn
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (chessboard[i][j] == '<' || chessboard[i][j] == '>') {
                    int leftMoves = 0;
                    int rightMoves = 0;
                    // Counting left movements
                    for (int k = j - 1; k >= 0; k--) {
                        if (chessboard[i][k] == '#') {
                            break;
                        }
                        leftMoves++;
                    }
                    // Counting right movements
                    for (int k = j + 1; k < m; k++) {
                        if (chessboard[i][k] == '#') {
                            break;
                        }
                        rightMoves++;
                    }
                    points += min(leftMoves, rightMoves);
                }
                if (chessboard[i][j] == '^' || chessboard[i][j] == 'v') {
                    int upMoves = 0;
                    int downMoves = 0;
                    // Counting up movements
                    for (int k = i - 1; k >= 0; k--) {
                        if (chessboard[k][j] == '#') {
                            break;
                        }
                        upMoves++;
                    }
                    // Counting down movements
                    for (int k = i + 1; k < n; k++) {
                        if (chessboard[k][j] == '#') {
                            break;
                        }
                        downMoves++;
                    }
                    points += min(upMoves, downMoves);
                }
            }
        }
        
        cout << points << endl;
    }
    
    return 0;
}