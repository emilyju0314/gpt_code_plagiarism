#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<char>> grid(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    vector<int> col_black(N, 0);
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            if (grid[i][j] == '#') {
                col_black[j]++;
            }
        }
    }

    int min_operations = N*N;
    for (int i = 0; i < N; i++) {
        vector<int> operations;
        for (int j = 0; j < N; j++) {
            operations.push_back(N - col_black[j] + (grid[i][j] == '#'));
        }
        sort(operations.begin(), operations.end());

        int total_ops = 0;
        for (int k = 0; k < N; k++) {
            total_ops += operations[k];
            min_operations = min(min_operations, total_ops + k);
        }
    }

    if (min_operations == N*N) {
        cout << -1 << endl;
    } else {
        cout << min_operations << endl;
    }

    return 0;
}