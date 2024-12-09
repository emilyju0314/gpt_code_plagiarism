#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

const int boardSize = 10;
double expectedTurns[boardSize][boardSize];

int main() {
    // Read input
    vector<vector<int>> ladders(boardSize, vector<int>(boardSize));
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            cin >> ladders[i][j];
        }
    }

    // Initialize expectedTurns array
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            expectedTurns[i][j] = -1.0;
        }
    }

    // Set the goal square
    expectedTurns[0][0] = 0.0;

    // Dynamic programming to fill the expectedTurns array
    for (int row = 0; row < boardSize; row++) {
        for (int col = 0; col < boardSize; col++) {
            if (expectedTurns[row][col] >= 0) {
                for (int i = 1; i <= 6; i++) {
                    int nextRow, nextCol;
                    if (col % 2 == 0) {
                        nextCol = col + i;
                        if (nextCol >= boardSize) {
                            nextRow = row + 1;
                            nextCol = boardSize - 1 - i;
                        } else {
                            nextRow = row;
                        }
                    } else {
                        nextCol = col - i;
                        if (nextCol < 0) {
                            nextRow = row + 1;
                            nextCol = i - 1;
                        } else {
                            nextRow = row;
                        }
                    }

                    nextRow = min(nextRow + ladders[nextRow][nextCol], boardSize - 1);
                    if (expectedTurns[nextRow][nextCol] < 0) {
                        expectedTurns[nextRow][nextCol] = expectedTurns[row][col] + 1.0;
                    } else {
                        expectedTurns[nextRow][nextCol] += expectedTurns[row][col] + 1.0;
                    }
                }
            }
        }
    }

    cout << fixed << setprecision(10) << expectedTurns[boardSize-1][0] << endl;

    return 0;
}