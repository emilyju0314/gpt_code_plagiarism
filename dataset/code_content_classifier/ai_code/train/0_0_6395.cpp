#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Cell {
    double x, y, z, r;
};

double distance(Cell a, Cell b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    double dz = a.z - b.z;
    return sqrt(dx*dx + dy*dy + dz*dz) - a.r - b.r;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<Cell> cells(n);
        
        for (int i = 0; i < n; i++) {
            cin >> cells[i].x >> cells[i].y >> cells[i].z >> cells[i].r;
        }
        
        vector<vector<double>> dist(n, vector<double>(n, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                dist[i][j] = max(0.0, distance(cells[i], cells[j]));
                dist[j][i] = dist[i][j];
            }
        }
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        
        double total = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                total += dist[i][j];
            }
        }
        
        cout << fixed << setprecision(3) << total << endl;
    }
    
    return 0;
}