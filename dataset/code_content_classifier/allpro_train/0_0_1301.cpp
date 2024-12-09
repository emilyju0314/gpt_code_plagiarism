#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

struct Edge {
    int to;
    int time;
};

struct Node {
    int town;
    int time;
    
    bool operator>(const Node& other) const {
        return time > other.time;
    }
};

int main() {
    int N, M;
    
    while (cin >> N >> M && N != 0 && M != 0) {
        vector<vector<Edge>> graph(N + 1);
        vector<char> routeTypes(M);
        
        for (int i = 0; i < M; i++) {
            int x, y, t;
            char sl;
            cin >> x >> y >> t >> sl;
            
            graph[x].push_back({y, t});
            graph[y].push_back({x, t});
            routeTypes[i] = sl;
        }
        
        int R;
        cin >> R;
        
        vector<int> destinations(R);
        for (int i = 0; i < R; i++) {
            cin >> destinations[i];
        }
        
        vector<int> dist(N + 1, INT_MAX);
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        
        pq.push({destinations[0], 0});
        dist[destinations[0]] = 0;
        
        while (!pq.empty()) {
            Node curr = pq.top();
            pq.pop();
            
            for (Edge& edge : graph[curr.town]) {
                int newTime = curr.time + edge.time;
                
                if (newTime < dist[edge.to]) {
                    dist[edge.to] = newTime;
                    pq.push({edge.to, newTime});
                }
            }
        }
        
        int totalTime = dist[destinations[0]];
        for (int i = 1; i < R; i++) {
            int seaTime = 0;
            bool found = false;
            
            for (int j = 0; j < M; j++) {
                if (routeTypes[j] == 'S' && ((destinations[i-1] == graph[j][0].to && destinations[i] == graph[j][1].to) || (destinations[i-1] == graph[j][1].to && destinations[i] == graph[j][0].to))) {
                    seaTime = graph[j].time;
                    found = true;
                    break;
                }
            }
            
            if (!found) {
                cout << "Error: Sea route not found!" << endl;
                break;
            }
            
            totalTime += min(dist[destinations[i]], seaTime);
        }
        
        cout << totalTime << endl;
    }
    
    return 0;
}