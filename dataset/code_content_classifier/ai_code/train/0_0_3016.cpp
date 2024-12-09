#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define INF INT_MAX

// Data structure to store graph edges
struct Edge {
    int source, dest, weight;
};

// Class to represent a graph object
class Graph {
public:
    // An array of vectors to represent the graph
    vector<vector<Edge>> adjList;

    // Constructor
    Graph(int N, int M) {
        // Resize the adjacency list to accommodate N nodes
        adjList.resize(N + 1);
    }

    // Function to add an edge to the graph
    void addEdge(int source, int dest, int weight) {
        adjList[source].push_back({source, dest, weight});
        adjList[dest].push_back({dest, source, weight});
    }

    // Function to find the shortest distance from source to all other nodes
    vector<int> dijkstra(int source, int N) {
        vector<int> dist(N + 1, INF);
        vector<bool> visited(N + 1, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            visited[u] = true;

            for (Edge edge : adjList[u]) {
                int v = edge.dest;
                int weight = edge.weight;

                if (!visited[v] && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }
};

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    Graph graph(N, M);

    // Read the road information
    for (int i = 0; i < M; i++) {
        int ai, bi, li;
        cin >> ai >> bi >> li;
        graph.addEdge(ai, bi, li);
    }

    // Read the shopping mall information
    vector<int> shoppingMalls;
    for (int i = 0; i < K; i++) {
        int si;
        cin >> si;
        shoppingMalls.push_back(si);
    }

    // Calculate the shortest distance from each town to the nearest shopping mall
    vector<vector<int>> distToMalls;
    for (int mall : shoppingMalls) {
        distToMalls.push_back(graph.dijkstra(mall, N));
    }

    // Find the minimum distance to the nearest shopping mall for each town
    int minDistance = INF;
    for (int i = 1; i <= N; i++) {
        int townDistance = 0;
        for (vector<int> dist : distToMalls) {
            townDistance += dist[i];
        }

        minDistance = min(minDistance, townDistance);
    }

    cout << minDistance << endl;

    return 0;
}