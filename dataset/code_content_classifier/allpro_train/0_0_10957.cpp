#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, char>>> adj(n + 1);
    vector<int> colors(m);
    for(int i = 0; i < m; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
        colors[i] = (c == 'R' ? 1 : 0);
    }

    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(pair<int, char> neighbor : adj[curr]) {
            int next = neighbor.first;
            int edgeColor = (neighbor.second == 'R' ? 1 : 0);
            if(dist[next] == -1) {
                dist[next] = dist[curr] + 1;
                if(edgeColor != colors[dist[next] % 2]) {
                    q.push(next);
                }
            }
        }
    }

    if(dist[n] == -1) {
        cout << -1 << endl;
    } else {
        cout << dist[n] << endl;
        
        vector<int> moves;
        int curr = n;
        while(curr != 1) {
            moves.push_back(curr);
            for(pair<int, char> neighbor : adj[curr]) {
                int next = neighbor.first;
                if(dist[next] == dist[curr] - 1) {
                    curr = next;
                    break;
                }
            }
        }
        moves.push_back(1);
        
        for(int i = moves.size() - 1; i >= 0; i--) {
            cout << moves[i] << " ";
        }
        cout << endl;
    }

    return 0;
}