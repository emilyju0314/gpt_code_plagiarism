#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> connections(2*N*N - 2*N);
    vector<vector<int>> grid(N, vector<int>(N, 0));

    for (int i = 0; i < 2*N*N - 2*N; i++) {
        int a, b;
        cin >> a >> b;
        connections[i] = make_pair(a, b);
    }

    // Initialize grid with first two connections, as their positions can be deduced directly
    grid[0][0] = connections[0].first;
    grid[0][1] = connections[0].second;

    // Deduce positions of the rest of the grid
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 0) {
                int topLeft = grid[i-1][j];
                int topRight = grid[i-1][j+1];

                pair<int, int> connection = make_pair(topLeft, topRight);

                if (find(connections.begin(), connections.end(), connection) != connections.end()) {
                    grid[i][j] = topLeft;
                    grid[i][j+1] = topRight;
                } else {
                    grid[i][j] = topRight;
                    grid[i][j+1] = topLeft;
                }
            }
        }
    }

    // Output the grid
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}