#include <iostream>
#include <vector>

using namespace std;

bool isValidClosedCurve(vector<vector<int>>& board) {
    int countOpenSquares = 0;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == 0) {
                countOpenSquares++;
            }
        }
    }
    if (countOpenSquares == 0) return false; // No closed curve possible if all squares are filled with stones

    // Check if closed curve is possible
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == 0) {
                int startX = i, startY = j;
                int currX = i, currY = j;
                bool visited[7][7] = {false};
                visited[currX][currY] = true;
                int openSquares = countOpenSquares - 1;
                while (openSquares > 0) {
                    int newX, newY;
                    // moving right
                    newX = currX;
                    newY = currY + 1;
                    if (newY >= 0 && newY < board[0].size() && board[newX][newY] == 0 && !visited[newX][newY]) {
                        currX = newX;
                        currY = newY;
                        visited[currX][currY] = true;
                        openSquares--;
                        continue;
                    }
                    // moving down
                    newX = currX + 1;
                    newY = currY;
                    if (newX >= 0 && newX < board.size() && board[newX][newY] == 0 && !visited[newX][newY]) {
                        currX = newX;
                        currY = newY;
                        visited[currX][currY] = true;
                        openSquares--;
                        continue;
                    }
                    // moving left
                    newX = currX;
                    newY = currY - 1;
                    if (newY >= 0 && newY < board[0].size() && board[newX][newY] == 0 && !visited[newX][newY]) {
                        currX = newX;
                        currY = newY;
                        visited[currX][currY] = true;
                        openSquares--;
                        continue;
                    }
                    // moving up
                    newX = currX - 1;
                    newY = currY;
                    if (newX >= 0 && newX < board.size() && board[newX][newY] == 0 && !visited[newX][newY]) {
                        currX = newX;
                        currY = newY;
                        visited[currX][currY] = true;
                        openSquares--;
                        continue;
                    }
                    return false; // No closed curve possible
                }
                break;
            }
        }
    }
    return true;
}

int main() {
    int W, H;
    while (cin >> W >> H && !(W == 0 && H == 0)) {
        vector<vector<int>> board(H, vector<int>(W));
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> board[i][j];
            }
        }
        if (isValidClosedCurve(board)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}