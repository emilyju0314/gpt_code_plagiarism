#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, q;
vector<vector<int>> adj;
vector<int> city;
vector<vector<int>> people;

void bfs(int v, int u, int a) {
    vector<int> dist(n+1, -1);
    vector<int> ans;
    queue<int> q;
    q.push(v);
    dist[v] = 0;
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        
        for (int neighbor : adj[curr]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[curr] + 1;
                q.push(neighbor);
            }
        }
    }
    
    int minPeople = min(dist[u] + 1, (int)city.size());
    ans.push_back(minPeople);
    
    sort(city.begin(), city.begin() + minPeople);
    
    for (int i = 0; i < minPeople; i++) {
        ans.push_back(city[i]);
    }
    
    for (int i = 1; i < minPeople; i++) {
        if (ans[i] > people[ans[i]][0]) {
            swap(ans[i], ans[1]);
            break;
        }
    }
    
    for (int i = 0; i < minPeople; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    cin >> n >> m >> q;
    
    adj.resize(n+1);
    city.resize(m);
    people.resize(n+1, vector<int>());
    
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    
    for (int i = 0; i < m; i++) {
        cin >> city[i];
        people[city[i]].push_back(i+1);
    }
    
    for (int i = 0; i < q; i++) {
        int v, u, a;
        cin >> v >> u >> a;
        bfs(v, u, a);
    }
    
    return 0;
}