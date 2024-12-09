#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> bridges(n, vector<int>());
    
    // Reading the bridges information
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        
        vector<int> distances(k);
        for (int j = 0; j < k; j++) {
            cin >> distances[j];
        }
        
        bridges[i] = distances;
    }
    
    int unstable_cells = 0;
    
    // Checking for unstable cells
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bridges[i].size(); j++) {
            int next_j = (j + 1) % bridges[i].size();
            for (int k = i + 1; k < n; k++) {
                for (int l = 0; l < bridges[k].size(); l++) {
                    int next_l = (l + 1) % bridges[k].size();
                    
                    if (bridges[i][j] != bridges[k][l] && bridges[i][next_j] != bridges[k][next_l]) {
                        unstable_cells++;
                    }
                }
            }
        }
    }
    
    cout << unstable_cells << endl;
    
    return 0;
}