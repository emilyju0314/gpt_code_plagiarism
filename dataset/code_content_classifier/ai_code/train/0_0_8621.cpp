#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<int> inDegree(n+1, 0);
        vector<int> outDegree(n+1, 0);
        vector<pair<int, int>> roads;
        
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            roads.push_back({u, v});
            outDegree[u]++;
            inDegree[v]++;
        }
        
        int maxCities = 0;
        for (int city = 1; city <= n; city++) {
            maxCities += (inDegree[city] == outDegree[city]);
        }
        
        cout << maxCities << endl;
        
        for (auto road : roads) {
            if (inDegree[road.second] < outDegree[road.second]) {
                cout << road.first << " " << road.second << endl;
            } else {
                cout << road.second << " " << road.first << endl;
            }
        }
    }
    
    return 0;
}