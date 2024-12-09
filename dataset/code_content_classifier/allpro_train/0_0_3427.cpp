#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n+1);
    vector<pair<int, int>> coordinates(n+1);
    vector<bool> visited(n+1, false);

    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    visited[1] = true;
    coordinates[1] = {0, 0};

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int neighbor : adj[cur]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);

                // Assign coordinates based on parent node
                if(coordinates[cur].first != coordinates[cur].second) {
                    coordinates[neighbor] = {coordinates[cur].first, coordinates[cur].first + 1};
                } else {
                    coordinates[neighbor] = {coordinates[cur].first + 1, coordinates[cur].second};
                }
            }
        }
    }

    // Check if the puzzle has a solution
    bool hasSolution = true;
    for(int i = 1; i <= n; i++) {
        if(coordinates[i].first == 0 && coordinates[i].second == 0) {
            hasSolution = false;
            break;
        }
    }

    if(hasSolution) {
        cout << "YES" << endl;
        for(int i = 1; i <= n; i++) {
            cout << coordinates[i].first << " " << coordinates[i].second << endl;
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}