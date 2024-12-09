#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<char>> grid(N, vector<char>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    int skewers = 0;

    // Count the number of skewers that can be made horizontally
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= M - 3; j++) {
            if ((grid[i][j] == 'R' || grid[i][j] == 'G' || grid[i][j] == 'W') &&
                (grid[i][j+1] == 'R' || grid[i][j+1] == 'G' || grid[i][j+1] == 'W') &&
                (grid[i][j+2] == 'R' || grid[i][j+2] == 'G' || grid[i][j+2] == 'W')) {
                skewers++;
            }
        }
    }

    // Count the number of skewers that can be made vertically
    for (int j = 0; j < M; j++) {
        for (int i = 0; i <= N - 3; i++) {
            if ((grid[i][j] == 'R' || grid[i][j] == 'G' || grid[i][j] == 'W') &&
                (grid[i+1][j] == 'R' || grid[i+1][j] == 'G' || grid[i+1][j] == 'W') &&
                (grid[i+2][j] == 'R' || grid[i+2][j] == 'G' || grid[i+2][j] == 'W')) {
                skewers++;
            }
        }
    }

    cout << skewers << endl;

    return 0;
}