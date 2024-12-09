#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Plan {
    int type;
    int v, u, l, r, w;
    
    Plan(int t, int x, int y, int z) : type(t), v(x), u(y), w(z) {}
    Plan(int t, int x, int y, int l, int r, int z) : type(t), v(x), l(l), r(r), w(z) {}
};

int main() {
    int n, q, s;
    cin >> n >> q >> s;
    
    vector<vector<Plan>> plans(n+1);
    for (int i = 0; i < q; i++) {
        int t, v, u, l, r, w;
        cin >> t;
        if (t == 1) {
            cin >> v >> u >> w;
            plans[v].push_back(Plan(t, v, u, w));
        } else {
            cin >> v >> l >> r >> w;
            plans[v].push_back(Plan(t, v, l, r, w));
        }
    }
    
    vector<int> dist(n+1, INT_MAX);
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    
    while (!pq.empty()) {
        int cost = pq.top().first;
        int planet = pq.top().second;
        pq.pop();
        
        if (cost > dist[planet]) continue;
        
        for (Plan& p : plans[planet]) {
            int new_cost = cost + p.w;
            if (p.type == 1) {
                if (new_cost < dist[p.u]) {
                    dist[p.u] = new_cost;
                    pq.push({dist[p.u], p.u});
                }
            } else if (p.type == 2) {
                for (int i = p.l; i <= p.r; i++) {
                    if (new_cost < dist[i]) {
                        dist[i] = new_cost;
                        pq.push({dist[i], i});
                    }
                }
            } else {
                if (new_cost < dist[p.v]) {
                    dist[p.v] = new_cost;
                    pq.push({dist[p.v], p.v});
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) {
            cout << -1 << " ";
        } else {
            cout << dist[i] << " ";
        }
    }
    
    return 0;
}