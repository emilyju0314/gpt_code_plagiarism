#include <iostream>
#include <vector>

using namespace std;

int main() {
    int w, d, n;
    cin >> w >> d >> n;

    vector<vector<int>> grid(w + 2, vector<int>(d + 2, 0));
    vector<vector<int>> measured(w + 2, vector<int>(d + 2, 0));

    for(int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        measured[x][y] = z;
    }

    int totalAltitude = 0;
    
    for(int i = 1; i <= w; i++) {
        for(int j = 1; j <= d; j++) {
            int minAltitude = measured[i][j];
            for(int x = i - 1; x <= i + 1; x++) {
                for(int y = j - 1; y <= j + 1; y++) {
                    minAltitude = min(minAltitude, measured[x][y] + abs(grid[i][j] - grid[x][y]));
                }
            }
            grid[i][j] = minAltitude;
            totalAltitude += grid[i][j];
        }
    }

    for(int i = 1; i <= w; i++) {
        for(int j = 1; j <= d; j++) {
            if(measured[i][j] != grid[i][j]) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << totalAltitude << endl;

    return 0;
}