#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> problemRoads;
vector<int> candidates;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        
        for (auto edge : adj[curr]) {
            int next = edge.first;
            int roadType = edge.second;
            if (candidates[curr] && roadType == 2 && !candidates[next]) {
                candidates[next] = 1;
                q.push(next);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    adj.resize(n+1);
    candidates.resize(n+1, 0);
    
    for (int i = 0; i < n-1; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        adj[x].push_back({y, t});
        adj[y].push_back({x, t});
        if (t == 2) {
            problemRoads.push_back(x);
        }
    }
    
    candidates[1] = 1;
    for (int p : problemRoads) {
        candidates[p] = 1;
        bfs(p);
    }
    
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (candidates[i]) {
            ans.push_back(i);
        }
    }
    
    cout << ans.size() << endl;
    for (int candidate : ans) {
        cout << candidate << " ";
    }
    
    return 0;
}