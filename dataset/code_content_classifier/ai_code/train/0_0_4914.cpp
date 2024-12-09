#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, A, B;
    cin >> N >> M >> A >> B;

    vector<vector<char>> grid(N, vector<char>(M, '.'));

    int remaining_A = A, remaining_B = B;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == '.') {
                if (j+1 < M && remaining_A >= 1) {
                    grid[i][j] = '<';
                    grid[i][j+1] = '>';
                    remaining_A--;
                    j++;
                } else if (i+1 < N && remaining_B >= 1) {
                    grid[i][j] = '^';
                    grid[i+1][j] = 'v';
                    remaining_B--;
                }
            }
        }
    }

    if (remaining_A == 0 && remaining_B == 0) {
        cout << "YES" << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}