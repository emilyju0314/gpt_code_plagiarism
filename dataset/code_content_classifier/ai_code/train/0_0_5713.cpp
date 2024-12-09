#include <iostream>
#include <vector>
using namespace std;

bool validMatrix(vector<vector<int>>& matrix, int K, int S) {
    int N = matrix.size();
    int M = matrix[0].size();

    for (int i = 0; i < N; i++) {
        int sum = 0;
        int count = 0;
        for (int j = 0; j < M; j++) {
            if (matrix[i][j] < 0) {
                count++;
                matrix[i][j] *= -1;
            }
            sum += matrix[i][j];
            if (count > K || sum > S) {
                return false;
            }
        }
    }

    for (int j = 0; j < M; j++) {
        int sum = 0;
        int count = 0;
        for (int i = 0; i < N; i++) {
            if (matrix[i][j] < 0) {
                count++;
                matrix[i][j] *= -1;
            }
            sum += matrix[i][j];
            if (count > K || sum > S) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int N, M, K, S;
    cin >> N >> M >> K >> S;

    vector<vector<int>> matrix(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }

    if (validMatrix(matrix, K, S)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}