#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    // Read the horizontal corridors' capacities
    vector<vector<int>> horizontal(n, vector<int>(m - 1));
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n; j++) {
            cin >> horizontal[j][i];
        }
    }
    
    // Read the vertical corridors' capacities
    vector<vector<int>> vertical(n - 1, vector<int>(m));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            cin >> vertical[j][i];
        }
    }
    
    // Calculate the total number of tentacles that can crawl out
    long long tentacles = 0;
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n; j++) {
            tentacles += min(horizontal[j][i], vertical[j][i]);
        }
    }
    
    cout << tentacles << endl;
    
    return 0;
}