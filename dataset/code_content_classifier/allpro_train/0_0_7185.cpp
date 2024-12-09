#include <iostream>
#include <vector>
#include <algorithm>

struct Edge {
    int u, v, w;
};

bool compare_edges(const Edge& e1, const Edge& e2) {
    return e1.w < e2.w;
}

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<Edge> edges(M);
    for(int i = 0; i < M; i++) {
        std::cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    std::sort(edges.begin(), edges.end(), compare_edges);

    long long total_cost = 0;
    for(const Edge& edge : edges) {
        total_cost += edge.w;
    }

    long long min_cost_diff = LLONG_MAX;
    int min_u = -1, min_v = -1;

    long long cost_a = 0, cost_b = total_cost;
    for(const Edge& edge : edges) {
        cost_a += edge.w;
        cost_b -= edge.w;

        long long cost_diff = std::abs(cost_a - cost_b);
        if(cost_diff < min_cost_diff) {
            min_cost_diff = cost_diff;
            min_u = std::min(edge.u, edge.v);
            min_v = std::max(edge.u, edge.v);
        }
    }

    std::cout << min_u << " " << min_v << std::endl;

    return 0;
}