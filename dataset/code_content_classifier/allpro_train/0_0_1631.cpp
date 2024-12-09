#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    int N, M, Q;
    cin >> N >> M;
    vector<vector<pair<int, int>>> graph(N);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a-1].push_back({b-1, c});
        graph[b-1].push_back({a-1, c});
    }

    cin >> Q;
    for (int q = 0; q < Q; q++) {
        int S, T;
        cin >> S >> T;
        S--; T--;

        vector<long long> distS(N, 1e18), distT(N, 1e18);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        distS[S] = 0;
        pq.push({0, S});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (distS[u] < d) continue;
            for (auto [v, w] : graph[u]) {
                if (distS[v] > d + w) {
                    distS[v] = d + w;
                    pq.push({distS[v], v});
                }
            }
        }

        distT[T] = 0;
        pq.push({0, T});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (distT[u] < d) continue;
            for (auto [v, w] : graph[u]) {
                if (distT[v] > d + w) {
                    distT[v] = d + w;
                    pq.push({distT[v], v});
                }
            }
        }

        long long min_cost = 1e18;
        for (int u = 0; u < N; u++) {
            for (auto [v, w] : graph[u]) {
                if ((distS[u] < distS[v] && distT[u] < distT[v]) || (distS[v] < distS[u] && distT[v] < distT[u])) {
                    min_cost = min(min_cost, distS[u] + distT[v] + w);
                }
            }
        }

        cout << min_cost << endl;
    }

    return 0;
}