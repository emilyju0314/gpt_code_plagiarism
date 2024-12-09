#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<int> switch_changes(n + 1, 0);
    
    for (int i = 1; i < n; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].push_back({v, d});
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    for (int i = 0; i < m; i++) {
        int s, t;
        cin >> s >> t;
        pq.push({t, s});
    }
    
    int latest_explosion_time = 0;
    int switch_changes_needed = 0;
    
    while (!pq.empty()) {
        int time = pq.top().first;
        int station = pq.top().second;
        pq.pop();
        
        int max_time_to_dest = 0;
        
        for (pair<int, int> edge : adj[station]) {
            int child, dist;
            tie(child, dist) = edge;
            
            max_time_to_dest = max(max_time_to_dest, dist);
        }
        
        if (time > latest_explosion_time) {
            latest_explosion_time = time;
            switch_changes_needed++;
        }
        
        int next_time = time + max_time_to_dest;
        
        for (pair<int, int> edge : adj[station]) {
            int child, dist;
            tie(child, dist) = edge;
            
            if (next_time > pq.top().first) {
                pq.push({next_time, child});
            } else {
                pq.push(pq.top());
                pq.pop();
                pq.push({next_time, child});
            }
            
            next_time++;
        }
    }
    
    cout << latest_explosion_time << " " << switch_changes_needed << endl;
    
    return 0;
}