#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> r(n), c(n);
    for(int i = 0; i < n; i++) {
        cin >> r[i];
    }
    
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }
    
    vector<vector<int>> grid(n, vector<int>(n, 0));
    vector<pair<int, int>> portals;
    
    for(int i = 0; i < n; i++) {
        if(grid[i][r[i] - 1] == 0) {
            grid[i][r[i] - 1] = 1;
            portals.push_back({i+1, r[i]});
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(grid[c[i] - 1][i] == 0) {
            grid[c[i] - 1][i] = 1;
            portals.push_back({c[i], i+1});
        }
    }
    
    if(portals.size() != n) {
        cout << -1 << endl;
    } else {
        cout << portals.size() << endl;
        for(auto portal : portals) {
            cout << portal.first << " " << 1 << " " << portal.first << " " << portal.second << endl;
        }
    }
    
    return 0;
}