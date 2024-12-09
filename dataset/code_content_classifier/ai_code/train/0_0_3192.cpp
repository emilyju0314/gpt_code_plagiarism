#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

const int INF = 1e9;

struct Node {
    int id, dist;
    vector<int> path;

    Node(int id, int dist, vector<int> path) {
        this->id = id;
        this->dist = dist;
        this->path = path;
    }

    bool operator<(const Node& other) const {
        if (dist != other.dist) return dist > other.dist;
        return path < other.path;
    }
};

struct Edge {
    int to, cost;

    Edge(int to, int cost) {
        this->to = to;
        this->cost = cost;
    }
};

void kthShortestPath(vector<vector<Edge>>& graph, int start, int end, int k) {
    vector<vector<int>> dist(graph.size(), vector<int>(k+1, INF));
    vector<vector<vector<int>>> path(graph.size(), vector<vector<int>>(k+1, vector<int>()));

    priority_queue<Node> pq;
    pq.push(Node(start, 0, {start}));
    dist[start][0] = 0;

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        if (cur.id == end) {
            if (cur.path.size() == k) {
                for (int node : cur.path) {
                    cout << node << "-";
                }
                cout << end << "\n";
                return;
            }
        }

        for (Edge& edge : graph[cur.id]) {
            int new_dist = cur.dist + edge.cost;
            int new_k = cur.path.size();
            vector<int> new_path = cur.path;
            new_path.push_back(edge.to);

            if (dist[edge.to][new_k] > new_dist) {
                dist[edge.to][new_k] = new_dist;
                path[edge.to][new_k] = new_path;
                pq.push(Node(edge.to, new_dist, new_path));
            }
        }
    }

    cout << "None\n";
}

int main() {
    int n, m, k, a, b;
    while (cin >> n >> m >> k >> a >> b) {
        if (n == 0 && m == 0 && k == 0 && a == 0 && b == 0) break;

        vector<vector<Edge>> graph(n+1);

        for (int i = 0; i < m; i++) {
            int x, y, d;
            cin >> x >> y >> d;
            graph[x].push_back(Edge(y, d));
        }

        kthShortestPath(graph, a, b, k);
    }

    return 0;
}