#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

const int MAXN = 50;
const int MAXM = 1225;
const int INF = 1e9;

struct Edge {
    int to, cost;
};

struct Node {
    int pos, cost;
    bool operator>(const Node& other) const {
        return cost > other.cost;
    }
};

int N, M, L, K;
vector<Edge> graph[MAXN + 1];
int dist[MAXN + 1][MAXN + 1];

void dijkstra(int start) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dist[i][j] = INF;
        }
    }

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({start, 0});

    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();

        int pos = node.pos;
        int cost = node.cost;

        if (dist[start][pos] != INF) continue;
        dist[start][pos] = cost;

        for (const Edge& edge : graph[pos]) {
            int to = edge.to;
            int new_cost = cost + edge.cost;
            pq.push({to, new_cost});
        }
    }
}

int main() {
    while (true) {
        cin >> N >> M >> L >> K;
        if (N == 0 && M == 0 && L == 0 && K == 0) break;

        for (int i = 1; i <= N; i++) {
            graph[i].clear();
        }

        for (int i = 0; i < M; i++) {
            int u, v, c;
            cin >> u >> v >> c;
            graph[u].push_back({v, c});
            graph[v].push_back({u, c});
        }

        int S, G;
        cin >> S >> G;

        for (int i = 0; i < L; i++) {
            int B;
            cin >> B;
        }

        dijkstra(S);

        vector<int> paths;
        for (int i = 1; i <= N; i++) {
            if (dist[S][i] != INF && dist[i][G] != INF) {
                paths.push_back(dist[S][i] + dist[i][G]);
            }
        }

        sort(paths.begin(), paths.end());
        
        if (K <= paths.size()) {
            cout << paths[K - 1] << endl;
        } else {
            cout << "NA" << endl;
        }
    }

    return 0;
}