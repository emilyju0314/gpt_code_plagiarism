#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    if (N % 2 != 0) {
        cout << -1 << endl;
        return 0;
    }

    vector<string> grid(N, string(N, '.'));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j += 2) {
            if (i % 2 == 0) {
                grid[i][j] = 'a' + j % 26;
                grid[i][j+1] = 'a' + j % 26;
            } else {
                grid[i][j] = grid[i-1][j];
                grid[i][j+1] = grid[i-1][j+1];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << grid[i] << endl;
    }

    return 0;
}