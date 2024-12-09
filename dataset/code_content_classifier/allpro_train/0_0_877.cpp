#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<char>> grid(n, vector<char>(n));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    
    vector<int> costs;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == '#') {
                int h = 1, w = 1;
                
                while(j+1 < n && grid[i][j+1] == '#') {
                    w++;
                    j++;
                }
                
                while(i+1 < n && grid[i+1][j] == '#') {
                    h++;
                    i++;
                }
                
                costs.push_back(max(h, w));
            }
        }
    }
    
    sort(costs.rbegin(), costs.rend());
    
    int total_cost = 0;
    int remaining_cells = n*n;
    
    for(int i = 0; i < costs.size(); i++) {
        total_cost += min(remaining_cells, costs[i]);
        remaining_cells -= costs[i];
    }
    
    cout << total_cost << endl;
    
    return 0;
}