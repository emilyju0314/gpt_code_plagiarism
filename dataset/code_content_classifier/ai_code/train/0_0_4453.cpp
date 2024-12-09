#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // Create a 2D array to represent the wall
    bool wall[n+1][n+1];
    memset(wall, false, sizeof(wall));

    // Mark the painted cells in the wall
    for (int i = 0; i < m; i++) {
        int r, c;
        cin >> r >> c;
        wall[r][c] = true;
    }

    // Initialize variables to store the total time and number of iterations
    double totalTime = 0;
    int iterations = 0;

    // Repeat the simulation until all rows and columns are painted
    while (true) {
        int paintedRows = 0, paintedCols = 0;
        
        // Randomly choose a tile to paint
        int r = rand() % n + 1;
        int c = rand() % n + 1;

        // Paint the selected tile if it is not already painted
        if (!wall[r][c]) {
            wall[r][c] = true;
            totalTime++;
        }

        // Check if all rows and columns are painted
        for (int i = 1; i <= n; i++) {
            paintedRows += wall[i][c];
            paintedCols += wall[r][i];
        }

        if (paintedRows == n && paintedCols == n) {
            break;
        }

        totalTime += 1.0; // Rest for one minute
        iterations++;
    }

    // Calculate and output the expected time to paint the wall
    double expectedTime = totalTime / iterations;
    cout << fixed << expectedTime << endl;

    return 0;
}