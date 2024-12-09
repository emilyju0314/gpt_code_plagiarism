#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n;
    
    while (true) {
        cin >> n;
        
        if (n == 0) {
            break;
        }
        
        vector<vector<int>> dist(10, vector<int>(10, INT_MAX));
        for (int i = 0; i < 10; i++) {
            dist[i][i] = 0;
        }
        
        for (int i = 0; i < n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            dist[a][b] = c;
            dist[b][a] = c;
        }
        
        for (int k = 0; k < 10; k++) {
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        int min_time = INT_MAX;
        int best_town = 0;
        
        for (int i = 0; i < 10; i++) {
            int total_time = 0;
            for (int j = 0; j < 10; j++) {
                total_time += dist[i][j];
            }
            if (total_time < min_time) {
                min_time = total_time;
                best_town = i;
            }
        }
        
        cout << best_town << " " << min_time << endl;
    }
    
    return 0;
}