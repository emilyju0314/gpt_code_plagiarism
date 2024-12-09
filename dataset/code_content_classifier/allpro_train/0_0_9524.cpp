#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, Q, A, B, C, D, E, F, G;
    cin >> N >> Q >> A >> B >> C >> D >> E >> F >> G;

    // Initialize the matrix
    vector<vector<int>> matrix(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = (i * A + j * B) % C;
        }
    }

    // Perform operations
    for (int i = 0; i < Q; i++) {
        char operation;
        cin >> operation;

        if (operation == 'WR') {
            int r, c, v;
            cin >> r >> c >> v;
            matrix[r-1][c-1] = v;
        } else if (operation == 'CP') {
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            matrix[r2-1][c2-1] = matrix[r1-1][c1-1];
        } else if (operation == 'SR') {
            int r1, r2;
            cin >> r1 >> r2;
            swap(matrix[r1-1], matrix[r2-1]);
        } else if (operation == 'SC') {
            int c1, c2;
            cin >> c1 >> c2;
            for (int r = 0; r < N; r++) {
                swap(matrix[r][c1-1], matrix[r][c2-1]);
            }
        } else if (operation == 'RL') {
            vector<vector<int>> temp(N, vector<int>(N));
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    temp[i][j] = matrix[j][N-1-i];
                }
            }
            matrix = temp;
        } else if (operation == 'RR') {
            vector<vector<int>> temp(N, vector<int>(N));
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    temp[i][j] = matrix[N-1-j][i];
                }
            }
            matrix = temp;
        } else if (operation == 'RH') {
            reverse(matrix.begin(), matrix.end());
        } else if (operation == 'RV') {
            for (int i = 0; i < N; i++) {
                reverse(matrix[i].begin(), matrix[i].end());
            }
        }
    }

    // Calculate hash value
    int hash = 314159265;
    for (int r = D; r <= E; r++) {
        for (int c = F; c <= G; c++) {
            hash = (31 * hash + matrix[r-1][c-1]) % 10000007;
        }
    }

    // Output the hash value
    cout << hash << endl;

    return 0;
}