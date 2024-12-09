#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // Initialize warehouse with empty spaces
    vector<vector<char>> warehouse(n, vector<char>(m, '.'));

    // Calculate the maximum number of turboplows that can be positioned in the warehouse
    int maxTurboplows = min(n / 3, m / 3);

    // Fill the warehouse with the turboplows
    char currentTurboplow = 'A';
    for (int i = 0; i < maxTurboplows; i++) {
        for (int j = i * 3; j < i * 3 + 3; j++) {
            for (int k = i * 3; k < i * 3 + 3; k++) {
                warehouse[j][k] = currentTurboplow;
            }
        }
        currentTurboplow++;
    }

    // Output the maximum number of turboplows and the filled warehouse
    cout << maxTurboplows << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << warehouse[i][j];
        }
        cout << endl;
    }

    return 0;
}