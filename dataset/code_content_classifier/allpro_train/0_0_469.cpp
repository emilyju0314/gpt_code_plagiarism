#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> distances(n);
    vector<int> heights(n);
    
    for (int i = 0; i < n; i++) {
        cin >> distances[i];
    }
    
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    
    int totalEnergy = 0;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        
        a--; // Adjust to 0-based indexing
        b--; // Adjust to 0-based indexing
        
        int energy = 2 * (heights[a] + heights[b]) + distances[a];
        
        // Check if children are playing between the two chosen trees
        // If children are playing, adjust the energy calculation
        if (a < b) {
            int childStart = a;
            int childEnd = b;
            int maxEnergy = 0;
            for (int j = a; j <= b; j++) {
                if (heights[j] > maxEnergy) {
                    maxEnergy = heights[j];
                }
            }
            energy += (maxEnergy * 2);
        } else {
            int childStart = b;
            int childEnd = a;
            int maxEnergy = 0;
            for (int j = 0; j < n; j++) {
                if ((j < childStart || j > childEnd) && heights[j] > maxEnergy) {
                    maxEnergy = heights[j];
                }
            }
            energy += (maxEnergy * 2);
        }
        
        totalEnergy += energy;
        cout << energy << endl;
    }
    
    return 0;
}