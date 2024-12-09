#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> grid(N);
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }

    int max_tiles = 0;
    vector<string> result(N, string(M, '.'));

    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < M-1; j++) {
            if (grid[i][j] == '.' && grid[i][j+1] == '.' && grid[i+1][j] == '.') {
                max_tiles++;
                result[i][j] = '>';
                result[i][j+1] = '<';
                result[i+1][j] = '^';
                result[i+1][j+1] = 'v';
            }
        }
    }

    cout << max_tiles << endl;
    for (int i = 0; i < N; i++) {
        cout << result[i] << endl;
    }

    return 0;
}