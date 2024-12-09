#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int v, cost;
};

struct Node {
    int town, tickets, cost;
    bool operator>(const Node& other) const {
        return cost > other.cost;
    }
};

int main() {
    int c, n, m, s, d;
    
    while (cin >> c >> n >> m >> s >> d) {
        if (c == 0 && n == 0 && m == 0 && s == 0 && d == 0) break;
        
        vector<vector<Edge>> graph(n+1);
        for (int i = 0; i < m; i++) {
            int a, b, f;
            cin >> a >> b >> f;
            graph[a].push_back({b, f});
            graph[b].push_back({a, f});
        }
        
        vector<vector<int>> dp(n+1, vector<int>(c+1, INT_MAX));
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        pq.push({s, 0, 0});
        dp[s][0] = 0;
        
        while (!pq.empty()) {
            Node curr = pq.top();
            pq.pop();
            
            if (curr.town == d) {
                cout << curr.cost << endl;
                break;
            }
            
            if (curr.cost > dp[curr.town][curr.tickets]) continue;
            
            for (Edge& e : graph[curr.town]) {
                int new_cost = curr.cost + e.cost;
                
                if (new_cost < dp[e.v][curr.tickets]) {
                    dp[e.v][curr.tickets] = new_cost;
                    pq.push({e.v, curr.tickets, new_cost});
                }
                
                if (curr.tickets < c && new_cost/2 < dp[e.v][curr.tickets+1]) {
                    dp[e.v][curr.tickets+1] = new_cost/2;
                    pq.push({e.v, curr.tickets+1, new_cost/2});
                }
            }
        }
    }
    
    return 0;
}