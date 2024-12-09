#include <iostream>
#include <vector>

using namespace std;

bool isValidCell(int row, int col, int n, int m) {
    return row >= 0 && row < n && col >= 0 && col < m;
}

bool isValidMatrix(vector<vector<int>>& costMatrix, vector<vector<char>>& directionMatrix, vector<vector<int>>& inputMatrix) {
    int n = costMatrix.size();
    int m = costMatrix[0].size();

    vector<vector<int>> resultMatrix(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int sum = 0;
            char direction = directionMatrix[i][j];

            int curRow = i;
            int curCol = j;

            while (isValidCell(curRow, curCol, n, m)) {
                sum += costMatrix[curRow][curCol];
                resultMatrix[curRow][curCol] = sum;

                if (direction == 'U') {
                    curRow--;
                } else if (direction == 'D') {
                    curRow++;
                } else if (direction == 'L') {
                    curCol--;
                } else if (direction == 'R') {
                    curCol++;
                }

                if (curRow == i && curCol == j) {
                    break;
                }
            }
        }
    }

    return resultMatrix == inputMatrix;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> inputMatrix(n, vector<int>(m));
        vector<vector<int>> costMatrix(n, vector<int>(m));
        vector<vector<char>> directionMatrix(n, vector<char>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> inputMatrix[i][j];
            }
        }

        bool foundSolution = false;
        for (int cost = 1; cost <= 100; cost++) {
            for (char direction = 'U'; direction <= 'R'; direction++) {
                costMatrix = vector<vector<int>>(n, vector<int>(m, cost));
                directionMatrix = vector<vector<char>>(n, vector<char>(m, direction));

                if (isValidMatrix(costMatrix, directionMatrix, inputMatrix)) {
                    foundSolution = true;
                    cout << "YES" << endl;

                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            cout << costMatrix[i][j] << " ";
                        }
                        cout << endl;
                    }

                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            cout << directionMatrix[i][j] << " ";
                        }
                        cout << endl;
                    }

                    break;
                }
            }
            if (foundSolution) {
                break;
            }
        }

        if (!foundSolution) {
            cout << "NO" << endl;
        }
    }

    return 0;
}