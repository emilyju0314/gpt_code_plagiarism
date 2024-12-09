#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, int>>> princesses(n+1);
    
    int a, b, w;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        princesses[a].push_back({b, w});
        princesses[b].push_back({a, w});
    }
    
    vector<int> maxDowry(n+1, 0);
    int totalDowry = 0;
    
    for (int i = 1; i <= n; i++) {
        vector<bool> visited(n+1, false);
        int currentMax = 0;
        for (pair<int, int> p : princesses[i]) {
            if (!visited[p.first]) {
                currentMax = max(currentMax, p.second);
                visited[p.first] = true;
            }
        }
        maxDowry[i] = currentMax;
        totalDowry += currentMax;
    }
    
    cout << totalDowry << endl;
    
    return 0;
}