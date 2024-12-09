#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<char>> grid(N, vector<char>(N));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    int count = 0;
    for(int i = 1; i < N; i += 2) {
        for(int j = 1; j < N; j += 2) {
            if(grid[i][j] == 'o') {
                count++;
                grid[i][j] = 'x';
                for(int k = i; k >= 0 && grid[k][j] == 'o'; k--) grid[k][j] = 'x';
                for(int k = i; k < N && grid[k][j] == 'o'; k++) grid[k][j] = 'x';
                for(int k = j; k >= 0 && grid[i][k] == 'o'; k--) grid[i][k] = 'x';
                for(int k = j; k < N && grid[i][k] == 'o'; k++) grid[i][k] = 'x';
            }
        }
    }

    cout << count << endl;

    return 0;
}