#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m, s;
    cin >> n >> m >> s;

    vector<vector<int>> graph(n+1);
    vector<bool> visited(n+1, false);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    queue<int> q;
    q.push(s);
    visited[s] = true;

    int reachable = 1; // Number of reachable cities including the capital

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(int neighbor : graph[curr]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
                reachable++;
            }
        }
    }

    int additional_roads = n - reachable;

    cout << additional_roads;

    return 0;
}