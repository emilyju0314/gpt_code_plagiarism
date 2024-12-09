#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int to;
    int weight;
    
    Edge(int t, int w) : to(t), weight(w) {}
};

int dijkstra(int N, int entrance, int monster, int H, vector<vector<Edge>>& graph) {
    priority_queue<pair<int, int>> pq; // {hit points, room}
    vector<int> maxHitPoints(N, INT_MIN);
    
    pq.push({H, entrance});
    maxHitPoints[entrance] = H;
    
    while (!pq.empty()) {
        int currHitPoints = pq.top().first;
        int currRoom = pq.top().second;
        pq.pop();
        
        if (currRoom == monster) {
            return currHitPoints;
        }
        
        for (const Edge& edge : graph[currRoom]) {
            int newHitPoints = currHitPoints + edge.weight;
            if (newHitPoints > maxHitPoints[edge.to]) {
                maxHitPoints[edge.to] = newHitPoints;
                pq.push({newHitPoints, edge.to});
            }
        }
    }
    
    return INT_MIN;
}

int main() {
    int testNum = 1;
    int N, M;
    
    while (cin >> N >> M) {
        if (N == 0 && M == 0) {
            break;
        }
        
        vector<vector<Edge>> graph(N);
        
        for (int i = 0; i < M; i++) {
            int fi, ti, wi;
            cin >> fi >> ti >> wi;
            graph[fi].push_back(Edge(ti, wi));
        }
        
        int s, t, H;
        cin >> s >> t >> H;
        
        int maxHitPoints = dijkstra(N, s, t, H, graph);
        
        cout << "Case " << testNum << ": ";
        if (maxHitPoints == INT_MIN) {
            cout << "GAME OVER" << endl;
        } else {
            cout << maxHitPoints << endl;
        }
        
        testNum++;
    }
    
    return 0;
}