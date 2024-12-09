#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<vector<int>> > sensorData(6, vector<vector<int>>(n, vector<int>(m, vector<int>(k)));
    
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < n; j++) {
            for (int p = 0; p < m; p++) {
                for (int q = 0; q < k; q++) {
                    cin >> sensorData[i][j][p][q];
                }
            }
        }
    }

    vector<vector<vector<int>> > blockData(n, vector<vector<int>>(m, vector<int>(k, 0));
    vector<int> blockTypes(200001, 0);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int p = 0; p < k; p++) {
                int type = -1;
                for (int sensor = 0; sensor < 6; sensor++) {
                    if ((i == 0 && j > 0 && p > 0) || 
                        (i == n-1 && j > 0 && p > 0) || 
                        (i > 0 && p > 0) || 
                        (i > 0 && j > 0)) {
                        for (int q = sensor-1; q >= 0; q--) {
                            if (sensorData[sensor][i][j][p] == sensorData[q][i][j][p]) {
                                type = sensorData[sensor][i][j][p];
                                break;
                            }
                        }
                    }
                }
                if (type == -1) {
                    cout << -1; // Inconsistent sensor data
                    return 0;
                }
                blockData[i][j][p] = type;
                blockTypes[type]++;
            }
        }
    }
    
    for (int i = 1; i <= 200000; i++) {
        if (blockTypes[i] > 2 * n*m + 2 * m*k + 2 * n*k) {
            cout << -1; // Inconsistent counts of block types
            return 0;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int p = 0; p < k; p++) {
                cout << blockData[i][j][p] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    return 0;
}