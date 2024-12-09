#include <iostream>
#include <vector>

using namespace std;

void rotateClockwise(vector<vector<int>>& matrix, int r, int c, int size) {
    vector<vector<int>> temp(size, vector<int>(size));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            temp[j][size - 1 - i] = matrix[r + i][c + j];
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[r + i][c + j] = temp[i][j];
        }
    }
}

void reverseSubmatrix(vector<vector<int>>& matrix, int r, int c, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[r + i][c + j] = 1 - matrix[r + i][c + j];
        }
    }
}

void leftShift(vector<vector<int>>& matrix, int r, int n) {
    vector<int> temp(matrix[r].begin(), matrix[r].begin() + n);
    for (int i = 0; i < matrix[r].size() - n; i++) {
        matrix[r][i] = matrix[r][i + n];
    }
    for (int i = 0; i < n; i++) {
        matrix[r][matrix[r].size() - n + i] = temp[i];
    }
}

void rightShift(vector<vector<int>>& matrix, int r, int n) {
    vector<int> temp(matrix[r].end() - n, matrix[r].end());
    for (int i = matrix[r].size() - 1; i >= n; i--) {
        matrix[r][i] = matrix[r][i - n];
    }
    for (int i = 0; i < n; i++) {
        matrix[r][i] = temp[i];
    }
}

void islandReverse(vector<vector<int>>& matrix, int r, int c) {
    matrix[r][c] = 1 - matrix[r][c];
    if (r - 1 >= 0) matrix[r - 1][c] = 1 - matrix[r - 1][c];
    if (r + 1 < matrix.size()) matrix[r + 1][c] = 1 - matrix[r + 1][c];
    if (c - 1 >= 0) matrix[r][c - 1] = 1 - matrix[r][c - 1];
    if (c + 1 < matrix[r].size()) matrix[r][c + 1] = 1 - matrix[r][c + 1];
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        int o;
        cin >> o;
        if (o == 0) {
            int r, c, size, angle;
            cin >> r >> c >> size >> angle;
            angle %= 360;
            while (angle > 0) {
                rotateClockwise(matrix, r, c, size);
                angle -= 90;
            }
        } else if (o == 1) {
            int r, c, size;
            cin >> r >> c >> size;
            reverseSubmatrix(matrix, r, c, size);
        } else if (o == 2) {
            int r;
            cin >> r;
            leftShift(matrix, r, n);
        } else if (o == 3) {
            int r;
            cin >> r;
            rightShift(matrix, r, n);
        } else if (o == 4) {
            int r, c;
            cin >> r >> c;
            islandReverse(matrix, r, c);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}