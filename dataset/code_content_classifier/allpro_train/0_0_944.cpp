#include <iostream>
#include <vector>

using namespace std;

// Function to toggle the lights
void toggleLights(vector<vector<int>>& lights, int x, int y, int d) {
    for (int i = 0; i < lights.size(); i++) {
        for (int j = 0; j < lights[0].size(); j++) {
            int dist = abs(i - x) + abs(j - y);
            if (dist <= d && (x != i || y != j)) {
                lights[i][j] = 1 - lights[i][j];
            }
        }
    }
}

int main() {
    int m, n, d;
    
    while (cin >> m >> n >> d) {
        if (m == 0 && n == 0 && d == 0) {
            break;
        }
        
        vector<vector<int>> lights(n, vector<int>(m));
        
        // Reading the initial state of lights
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> lights[i][j];
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (lights[i][j] == 1) {
                    toggleLights(lights, i, j, d);
                }
            }
        }
        
        bool allLightsOff = true;
        
        // Checking if all lights are off
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (lights[i][j] == 1) {
                    allLightsOff = false;
                    break;
                }
            }
        }
        
        // Output
        if (allLightsOff) {
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
        }
    }
    
    return 0;
}