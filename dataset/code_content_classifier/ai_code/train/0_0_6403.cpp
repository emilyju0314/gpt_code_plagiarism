#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

struct City {
    int population;
    vector<pair<int, int>> neighbors; // {destination city, cost}
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<City> cities(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> cities[i].population;
    }

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cities[a].neighbors.push_back({b, c});
        cities[b].neighbors.push_back({a, c});
    }

    int K;
    cin >> K;

    for (int k = 0; k < K; k++) {
        int x, d, p;
        cin >> x >> d >> p;

        vector<int> dist(N+1, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {cost, city}
        dist[x] = 0;
        pq.push({0, x});

        while (!pq.empty()) {
            int cost = pq.top().first;
            int current_city = pq.top().second;
            pq.pop();

            if (dist[current_city] < cost) {
                continue;
            }

            for (auto neighbor : cities[current_city].neighbors) {
                int neighbor_city = neighbor.first;
                int neighbor_cost = neighbor.second;
                if (dist[neighbor_city] > cost + neighbor_cost) {
                    dist[neighbor_city] = cost + neighbor_cost;
                    pq.push({dist[neighbor_city], neighbor_city});
                }
            }
        }

        int min_cost = INF;
        for (int i = 1; i <= N; i++) {
            if (dist[i] <= d) {
                min_cost = min(min_cost, max(dist[i], p));
            }
        }

        cout << min_cost - p << endl;
    }

    return 0;
}