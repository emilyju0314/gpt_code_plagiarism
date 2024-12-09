#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> adjacent[n+1];
    unordered_map<int, int> kitten_cells;
    
    for (int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        adjacent[x].push_back(y);
        adjacent[y].push_back(x);
    }
    
    vector<int> result(n);
    result[0] = 1;
    
    kitten_cells[1] = 1;
    
    for (int i = 0; i < adjacent[1].size(); i++) {
        int neighbor = adjacent[1][i];
        kitten_cells[neighbor] = 1;
    }
    
    for (int i = 1; i < n; i++) {
        int current = result[i-1];
        for (int j = 0; j < adjacent[current].size(); j++) {
            int neighbor = adjacent[current][j];
            if (kitten_cells.find(neighbor) == kitten_cells.end()) {
                result[i] = neighbor;
                kitten_cells[neighbor] = 1;
                break;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    
    return 0;
}