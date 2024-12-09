#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    vector<int> indegree(n+1, 0);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }

    int chosenIntersection = -1;
    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) {
            chosenIntersection = i;
            break;
        }
    }

    cout << chosenIntersection << endl;

    return 0;
}