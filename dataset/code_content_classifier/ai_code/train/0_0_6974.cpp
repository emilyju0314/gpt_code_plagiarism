#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<bool> isGovernment(n+1, false);
    for(int i = 0; i < k; i++) {
        int gov;
        cin >> gov;
        isGovernment[gov] = true;
    }

    vector<vector<int>> graph(n+1, vector<int>());
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int maxEdges = 0;
    for(int i = 1; i <= n; i++) {
        if(isGovernment[i]) {
            int connectedGovs = 0;
            for(int j : graph[i]) {
                if(isGovernment[j]) {
                    connectedGovs++;
                }
            }
            maxEdges += (k - connectedGovs);
        }
    }

    cout << maxEdges / 2 << endl; // Each edge was counted twice
    return 0;
}