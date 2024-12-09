#include <iostream>
#include <vector>

struct Edge {
    int from, to, weight;
};

const int INF = 1e9;

int main() {
    int V, E, w;
    std::cin >> V >> E >> w;

    std::vector<Edge> edges(E);
    for (int i = 0; i < E; i++) {
        std::cin >> edges[i].from >> edges[i].to >> edges[i].weight;
    }

    int max_sum = -INF;
    
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i != j) {
                edges.push_back({i, j, w});

                std::vector<int> dist(V, INF);
                dist[0] = 0;

                for (int k = 0; k < V - 1; k++) {
                    for (const auto& edge : edges) {
                        if (dist[edge.from] + edge.weight < dist[edge.to]) {
                            dist[edge.to] = dist[edge.from] + edge.weight;
                        }
                    }
                }

                for (const auto& edge : edges) {
                    if (dist[edge.from] + edge.weight < dist[edge.to]) {
                        max_sum = std::max(max_sum, dist[edge.to]);
                    }
                }

                edges.pop_back();
            }
        }
    }

    if (max_sum == -INF) {
        std::cout << "NA" << std::endl;
    } else {
        std::cout << max_sum << std::endl;
    }

    return 0;
}