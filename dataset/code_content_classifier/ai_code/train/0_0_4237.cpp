#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int dijkstra(vector<vector<pair<int, int>>>& graph, int start, int end) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distance(graph.size(), INT_MAX);
    
    pq.push({0, start});
    distance[start] = 0;
    
    while (!pq.empty()) {
        int curr = pq.top().second;
        int currDist = pq.top().first;
        pq.pop();
        
        if(curr == end) {
            return distance[end];
        }
        
        if(currDist > distance[curr]) {
            continue;
        }
        
        for(auto edge : graph[curr]) {
            int next = edge.first;
            int nextDist = edge.second + currDist;
            
            if(nextDist < distance[next]) {
                distance[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
    return -1;
}

int main() {
    int n, m, s, g1, g2;
    
    while (cin >> n >> m >> s >> g1 >> g2) {
        if (n == 0 && m == 0 && s == 0 && g1 == 0 && g2 == 0) {
            break;
        }
        
        vector<vector<pair<int, int>>> graph(n + 1);
        
        for (int i = 0; i < m; i++) {
            int b1, b2, c;
            cin >> b1 >> b2 >> c;
            graph[b1].push_back({b2, c});
        }
        
        int cost1 = dijkstra(graph, s, g1) + dijkstra(graph, g1, g2);
        int cost2 = dijkstra(graph, s, g2) + dijkstra(graph, g2, g1);
        
        cout << min(cost1, cost2) << endl;
    }
    
    return 0;
}