#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    vector<int> indegree(n+1, 0);
    vector<int> outdegree(n+1, 0);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[y].push_back(x);
        indegree[x]++;
        outdegree[y]++;
    }

    int separateCities = 0;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0 && outdegree[i] == 0) {
            separateCities++;
        }
    }

    cout << separateCities << endl;

    return 0;
}