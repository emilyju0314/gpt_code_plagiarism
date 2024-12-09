#include <iostream>
#include <vector>

#define INF 1e9

struct Edge {
    int source, target, cost;
};

void bellmanFord(const std::vector<Edge>& edges, int V, int E, int source) {
    std::vector<int> dist(V, INF);
    dist[source] = 0;

    for(int i = 0; i < V - 1; i++) {
        for(int j = 0; j < E; j++) {
            int u = edges[j].source;
            int v = edges[j].target;
            int cost = edges[j].cost;

            if(dist[u] != INF && dist[u] + cost < dist[v]) {
                dist[v] = dist[u] + cost;
            }
        }
    }

    for(int j = 0; j < E; j++) {
        int u = edges[j].source;
        int v = edges[j].target;
        int cost = edges[j].cost;

        if (dist[u] != INF && dist[u] + cost < dist[v]) {
            std::cout << "NEGATIVE CYCLE\n";
            return;
        }
    }

    for(int i = 0; i < V; i++) {
        if(dist[i] == INF) {
            std::cout << "INF\n";
        } else {
            std::cout << dist[i] << "\n";
        }
    }
}

int main() {
    int V, E, source;
    std::cin >> V >> E >> source;

    std::vector<Edge> edges(E);
    for(int i = 0; i < E; i++) {
        std::cin >> edges[i].source >> edges[i].target >> edges[i].cost;
    }

    bellmanFord(edges, V, E, source);

    return 0;
}