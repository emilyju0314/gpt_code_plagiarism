#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotateRight(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int i = 0; i < n; i++) {
        rotate(matrix[i].begin(), matrix[i].end() - 1, matrix[i].end());
    }
}

void rotateLeft(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int i = 0; i < n; i++) {
        rotate(matrix[i].begin(), matrix[i].begin() + 1, matrix[i].end());
    }
}

void rotateDown(vector<vector<int>>& matrix) {
    int n = matrix.size();
    rotate(matrix.begin(), matrix.end() - 1, matrix.end());
}

void rotateUp(vector<vector<int>>& matrix) {
    int n = matrix.size();
    rotate(matrix.begin(), matrix.begin() + 1, matrix.end());
}

void inverseRows(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

void inverseColumns(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int j = 0; j < n; j++) {
        vector<int> temp;
        for(int i = 0; i < n; i++) {
            temp.push_back(matrix[i][j]);
        }

        for(int i = 0; i < n; i++) {
            matrix[i][j] = temp[i];
        }
    }
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> matrix(n, vector<int>(n));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        string operations;
        cin >> operations;

        for(int k = 0; k < m; k++) {
            char op = operations[k];
            if(op == 'R') {
                rotateRight(matrix);
            } else if (op == 'L') {
                rotateLeft(matrix);
            } else if (op == 'D') {
                rotateDown(matrix);
            } else if (op == 'U') {
                rotateUp(matrix);
            } else if (op == 'I') {
                inverseRows(matrix);
            } else if (op == 'C') {
                inverseColumns(matrix);
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}