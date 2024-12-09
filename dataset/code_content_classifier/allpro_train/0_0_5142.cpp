#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> monitor(n);
    for(int i = 0; i < n; i++) {
        cin >> monitor[i];
    }

    int minX = n, minY = m, maxX = -1, maxY = -1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(monitor[i][j] == 'w') {
                minX = min(minX, i);
                minY = min(minY, j);
                maxX = max(maxX, i);
                maxY = max(maxY, j);
            }
        }
    }

    // Check if there are any white pixels
    if(minX == n) {
        cout << -1 << endl;
        return 0;
    }

    // Determine the size of the frame
    int size = max(maxX - minX, maxY - minY) + 1;

    // Mark the frame on the monitor
    for(int i = minX; i <= maxX; i++) {
        monitor[i][minY] = '+';
        monitor[i][maxY] = '+';
    }

    for(int j = minY; j <= maxY; j++) {
        monitor[minX][j] = '+';
        monitor[maxX][j] = '+';
    }

    // Print the resulting monitor screen
    for(int i = 0; i < n; i++) {
        cout << monitor[i] << endl;
    }

    return 0;
}