#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    vector<int> dist(n+1, -1);
    vector<int> parent(n+1, -1);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    dist[1] = 0;
    q.push(1);

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(int neighbor : adj[curr]) {
            if(dist[neighbor] == -1) {
                dist[neighbor] = dist[curr] + 1;
                parent[neighbor] = curr;
                q.push(neighbor);
            }
        }
    }

    int cycleLength = -1;
    vector<int> cycleVertices;

    for(int i = 1; i <= n; i++) {
        if(dist[i] >= sqrt(n)+1) {
            cycleLength = dist[i] + 1;
            cycleVertices.push_back(i);
            int curr = parent[i];
            while(curr != i) {
                cycleVertices.push_back(curr);
                curr = parent[curr];
            }
            cycleVertices.push_back(i);
            break;
        }
    }

    if(cycleLength == -1) {
        cout << "1" << endl;
        int setSize = ceil(sqrt(n));
        vector<int> independentSet;
        for(int i = 1; i <= n; i++) {
            if(independentSet.size() == setSize) break;
            if(find(cycleVertices.begin(), cycleVertices.end(), i) == cycleVertices.end()) {
                independentSet.push_back(i);
            }
        }
        for(int vertex : independentSet) {
            cout << vertex << " ";
        }
    } else {
        cout << "2" << endl;
        cout << cycleLength << endl;
        for(int i = cycleVertices.size() - 1; i >= 0; i--) {
            cout << cycleVertices[i] << " ";
        }
    }

    return 0;
}