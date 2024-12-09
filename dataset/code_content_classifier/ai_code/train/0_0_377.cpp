#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    vector<vector<int>> adj(n);
    vector<int> indegree(n);
    
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x-1].push_back(y-1);
        indegree[y-1]++;
    }
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            pq.push(i);
        }
    }
    
    int total_energy = 0;
    while (!pq.empty()) {
        int curr = pq.top();
        pq.pop();
        
        total_energy += v[curr];
        
        for (int next : adj[curr]) {
            indegree[next]--;
            if (indegree[next] == 0) {
                pq.push(next);
            }
        }
    }
    
    cout << total_energy << endl;
    
    return 0;
}