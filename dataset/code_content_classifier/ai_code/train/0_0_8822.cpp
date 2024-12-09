#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> flipEntry(vector<vector<int>> A, int i, int j) {
    A[i][j] = 1 - A[i][j]; // Flipping the entry
    return A;
}

int rank(matrix) {
    // Implementation of rank calculation for a given matrix
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> A(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            A[i][j] = row[j] - '0';
        }
    }

    int r = rank(A);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vector<vector<int>> A_flipped = flipEntry(A, i, j);
            int r_ij = rank(A_flipped);

            if (r_ij < r) {
                cout << "-";
            } else if (r_ij == r) {
                cout << "0";
            } else {
                cout << "+";
            }
        }
        cout << endl;
    }

    return 0;
}