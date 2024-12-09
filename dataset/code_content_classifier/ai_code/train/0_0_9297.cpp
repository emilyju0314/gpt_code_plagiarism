#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, vx, vy;
    cin >> n >> vx >> vy;
    
    vector<vector<int>> towers(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> towers[i][j];
        }
    }

    int visibleCubes = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int dx = i + 1;
            int dy = j + 1;

            int numVisible = 1; // count the current tower in the visible cubes

            // check for visible cubes in the direction of vector -v
            while (true) {
                int nextX = dx - vx;
                int nextY = dy - vy;

                if (nextX < 1 || nextY < 1 || nextX > n || nextY > n) break; // out of bounds

                if (towers[dx - 1][dy - 1] <= towers[nextX - 1][nextY - 1]) break; // not visible

                dx = nextX;
                dy = nextY;
                numVisible++;
            }

            visibleCubes += numVisible;
        }
    }

    cout << visibleCubes << endl;

    return 0;
}