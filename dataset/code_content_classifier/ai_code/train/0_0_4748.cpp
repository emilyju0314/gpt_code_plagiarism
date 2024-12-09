#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> paper(10, vector<int>(10, 0)); // Initialize 10x10 paper with density value 0
    int drops;
    cin >> drops;

    int x, y, size;
    for (int i = 0; i < drops; i++) {
        cin >> x >> y >> size;
        paper[x][y] += 1; // Increase density at the point of fall

        if (size == 1) {
            if (x-1 >= 0) paper[x-1][y] += 1; // Small ink sinks to left
            if (x+1 < 10) paper[x+1][y] += 1; // Small ink sinks to right
            if (y-1 >= 0) paper[x][y-1] += 1; // Small ink sinks up
            if (y+1 < 10) paper[x][y+1] += 1; // Small ink sinks down
        }
        else if (size == 2) {
            // Medium ink sinks in a 3x3 grid around the point of fall
            for (int j = x-1; j <= x+1; j++) {
                for (int k = y-1; k <= y+1; k++) {
                    if (j >= 0 && j < 10 && k >= 0 && k < 10) {
                        paper[j][k] += 1;
                    }
                }
            }
        }
        else if (size == 3) {
            // Large ink sinks in a 5x5 grid around the point of fall
            for (int j = x-2; j <= x+2; j++) {
                for (int k = y-2; k <= y+2; k++) {
                    if (j >= 0 && j < 10 && k >= 0 && k < 10) {
                        paper[j][k] += 1;
                    }
                }
            }
        }
    }

    int cells_with_density_zero = 0;
    int max_density = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (paper[i][j] == 0) {
                cells_with_density_zero += 1;
            }
            if (paper[i][j] > max_density) {
                max_density = paper[i][j];
            }
        }
    }

    cout << cells_with_density_zero << endl;
    cout << max_density << endl;

    return 0;
}