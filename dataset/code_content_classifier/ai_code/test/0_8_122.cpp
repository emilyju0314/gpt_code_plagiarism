#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
 
using namespace std;
 
vector<vector<pair<int, int>>> adj;
vector<int> light;
vector<vector<int>> answer;
vector<int> lights;
 
void dfs(int v, int par, int x) {
    for (auto edge : adj[v]) {
        int u = edge.first;
        int idx = edge.second;
        if (u == par) continue;
        if (x == -1) {
            answer[idx] = {v, u, lights[v]};
            dfs(u, v, lights[v]);
        } else {
            answer[idx] = {v, u, x};
            dfs(u, v, x);
        }
    }
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        adj.resize(n);
        light.resize(n);
        answer.resize(n - 1);
 
        for (int i = 0; i < n - 1; i++) {
            int x, y, v;
            cin >> x >> y >> v;
            x--; y--;
            light[x] = v;
            light[y] = v;
            adj[x].push_back({y, i});
            adj[y].push_back({x, i});
        }
        
        lights.resize(n);
        vector<int> elves;
        elves.reserve(m);
        for (int i = 0; i < m; i++) {
            int a, b, p;
            cin >> a >> b >> p;
            a--;
            b--;
            elves.push_back(a);
            elves.push_back(b);
            lights[a] = lights[b] = p;
        }
 
        dfs(0, -1, -1);
 
        bool possible = true;
        for (int i = 0; i < n; i++) {
            if (i < n - 1 && answer[i][2] == -1) {
                possible = false;
                break;
            }
        }
 
        if (possible) {
            cout << "YES" << endl;
            for (int i = 0; i < n - 1; i++) {
                cout << answer[i][0]+1 << " " << answer[i][1]+1 << " " << answer[i][2] << endl;
            }
        } else {
            cout << "NO" << endl;
        }
 
        adj.clear();
        light.clear();
        answer.clear();
        lights.clear();
    }
 
    return 0;
}