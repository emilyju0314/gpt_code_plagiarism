#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> droids(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> droids[i][j];
        }
    }

    vector<int> shots(m, 0);
    int max_droids = 0;
    for(int i = 0; i < n; i++) {
        vector<int> temp(m, 0);
        int total_droids = 0;
        for(int j = 0; j < n; j++) {
            bool all_destroyed = true;
            int total_shots = 0;
            for(int l = 0; l < m; l++) {
                int shots_needed = max(0, droids[j][l] - temp[l]);
                total_shots += shots_needed;
                if(shots_needed > 0) {
                    all_destroyed = false;
                    temp[l] += shots_needed;
                }
            }
            if(total_shots <= k && !all_destroyed) {
                total_droids++;
                shots = temp;
            } else {
                break;
            }
        }
        if(total_droids > max_droids) {
            max_droids = total_droids;
        }
    }

    for(int i = 0; i < m; i++) {
        cout << shots[i] << " ";
    }
    
    return 0;
}