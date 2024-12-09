#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

#define MAX 20005
#define INF numeric_limits<int>::max()

struct Edge {
    int to;
    int cost;
};

int H, W;
int A[MAX];
int c[10][10];
int dist[10];
vector<Edge> graph[10];

void dijkstra(int start) {
    fill(dist, dist + 10, INF);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        if (dist[node] < d) {
            continue;
        }

        for (auto& edge : graph[node]) {
            int next_node = edge.to;
            int cost = edge.cost;
            if (dist[next_node] > dist[node] + cost) {
              dist[next_node] = dist[node] + cost;
              pq.push(make_pair(dist[next_node], next_node));
            }
        }
    }
}

int main() {
    cin >> H >> W;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> c[i][j];
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i * W + j];
        }
    }

    // Construct the graph
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            graph[i].push_back({j, c[i][j]});
        }
    }

    // Perform Dijkstra's algorithm from every node
    int ans = 0;
    for (int i = 0; i < 10; i++) {
        dijkstra(i);
        // Accumulate the cost of turning all the digits into 1
        for (int k = 0; k < 10; k++) {
            ans += dist[k];
        }
    }

    cout << ans << endl;

    return 0;
}