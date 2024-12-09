#include <iostream>
#include <vector>
#include <queue>

const int MOD = 1e9 + 7;

struct Edge {
    int to, cost;
};

int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<Edge>> graph(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int a, b, x;
        std::cin >> a >> b >> x;
        if (x == 0) {
            graph[a].push_back({b, 0});
            graph[b].push_back({a, 0});
        } else {
            graph[a].push_back({b, 1});
        }
    }

    int K;
    std::cin >> K;

    std::vector<int> stops(K);
    for (int i = 0; i < K; i++) {
        std::cin >> stops[i];
    }

    std::vector<long long> dist(N + 1, LLONG_MAX);
    dist[1] = 0;

    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [cost, node] = pq.top();
        pq.pop();

        if (dist[node] < cost) continue;

        for (const Edge& edge : graph[node]) {
            int to = edge.to;
            int new_cost = cost + edge.cost;

            if (new_cost < dist[to]) {
                dist[to] = new_cost;
                pq.push({new_cost, to});
            }
        }
    }

    long long total_bribe = 0;
    for (int i = 1; i < K; i++) {
        total_bribe = (total_bribe * 2 + dist[stops[i]]) % MOD;
    }

    std::cout << total_bribe << std::endl;

    return 0;
}