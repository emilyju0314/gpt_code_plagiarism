#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

struct Edge {
    int source, target, cost;
};

void bellmanFord(vector<vector<int>>& distance, vector<Edge>& edges, int V, int E) {
    for (int i = 0; i < V; i++) {
        distance[i][i] = 0;
    }
    
    for (int i = 0; i < V - 1; i++) {
        for (Edge edge : edges) {
            if (distance[edge.source][i] != INF && distance[edge.source][i] + edge.cost < distance[edge.target][i]) {
                distance[edge.target][i] = distance[edge.source][i] + edge.cost;
            }
        }
    }
    
    for (int i = 0; i < V; i++) {
        for (Edge edge : edges) {
            if (distance[edge.source][V - 1] != INF && distance[edge.source][V - 1] + edge.cost < distance[edge.target][V - 1]) {
                cout << "NEGATIVE CYCLE" << endl;
                return;
            }
        }
    }
    
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (distance[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << distance[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    
    vector<Edge> edges(E);
    vector<vector<int>> distance(V, vector<int>(V, INF));
    
    for (int i = 0; i < E; i++) {
        int source, target, cost;
        cin >> source >> target >> cost;
        edges[i] = {source, target, cost};
        distance[source][target] = cost;
    }
    
    bellmanFord(distance, edges, V, E);
    
    return 0;
}