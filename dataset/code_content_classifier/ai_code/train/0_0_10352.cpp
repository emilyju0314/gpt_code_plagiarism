#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> costs(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> costs[i][j];
        }
    }

    int minMaxCost = INT_MAX;
    for (int i = 0; i < n; i++) {
        int maxCostInStreet = *max_element(costs[i].begin(), costs[i].end());
        minMaxCost = min(minMaxCost, maxCostInStreet);
    }

    cout << minMaxCost << endl;

    return 0;
}