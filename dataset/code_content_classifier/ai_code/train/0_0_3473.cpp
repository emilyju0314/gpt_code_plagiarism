#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <map>

using namespace std;

struct Node {
    int id;
    int cost;
};

class Graph {
public:
    int n;
    vector<vector<int>> adj;
    vector<int> dist;
    vector<int> parent;
    
    Graph(int n) {
        this->n = n;
        adj.resize(n);
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dijkstra(int start) {
        dist.assign(n, INT_MAX);
        parent.assign(n, -1);

        priority_queue<Node, vector<Node>, function<bool(Node, Node)>> pq(
            [](Node a, Node b) { return a.cost > b.cost; }
        );

        dist[start] = 0;
        pq.push({start, 0});

        while (!pq.empty()) {
            Node node = pq.top();
            pq.pop();

            int u = node.id;
            for (int v : adj[u]) {
                int weight = 1;
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                    pq.push({v, dist[v]});
                }
            }
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    Graph graph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u-1, v-1);
    }

    int s, b, k, h;
    cin >> s >> b >> k >> h;

    vector<int> spaceships_x(s), spaceships_a(s), spaceships_f(s);
    for (int i = 0; i < s; i++) {
        cin >> spaceships_x[i] >> spaceships_a[i] >> spaceships_f[i];
    }

    vector<int> bases_x(b), bases_d(b);
    for (int i = 0; i < b; i++) {
        cin >> bases_x[i] >> bases_d[i];
    }

    vector<int> dummy_bases;
    for (int i = 0; i < n; i++) {
        if (find(bases_x.begin(), bases_x.end(), i) == bases_x.end()) {
            dummy_bases.push_back(i);
        }
    }

    graph.dijkstra(0);

    int min_cost = 0;
    map<int, bool> attacked_bases;

    for (int i = 0; i < s; i++) {
        int sp = spaceships_x[i] - 1;
        int attackable_base = -1;
        int cost_to_base = INT_MAX;

        for (int j = 0; j < b; j++) {
            int base = bases_x[j] - 1;
            if (spaceships_a[i] >= bases_d[j] && spaceships_f[i] >= graph.dist[base]) {
                if (graph.dist[base] < cost_to_base) {
                    cost_to_base = graph.dist[base];
                    attackable_base = j;
                }
            }
        }

        if (attackable_base != -1) {
            attacked_bases[attackable_base] = true;
        } else {
            min_cost += h;
        }
    }

    for (int i = 0; i < b; i++) {
        if (attacked_bases.find(i) == attacked_bases.end()) {
            min_cost += k;
        }
    }

    cout << min_cost << endl;

    return 0;
}