#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int x, y, w, p;
};

vector<vector<int>> adj;
vector<Edge> edges;
vector<int> subtree_weights;

int calculateSubtreeWeight(int vertex) {
    int weight = edges[vertex].w;
    for (int next : adj[vertex]) {
        weight += calculateSubtreeWeight(next);
    }
    return subtree_weights[vertex] = weight;
}

bool adjustWeights(int vertex, int total_weight) {
    int required_weight = 0;
    for (int next : adj[vertex]) {
        if (!adjustWeights(next, total_weight)) return false;
        required_weight += (subtree_weights[next] > edges[next].p) ? subtree_weights[next] - edges[next].p : 0;
    }
    if (required_weight > total_weight) return false;
    edges[vertex].w += total_weight - required_weight;
    return true;
}

int main() {
    int n;
    cin >> n;

    adj.resize(n);
    edges.resize(n);
    subtree_weights.resize(n);

    for (int i = 1; i < n; i++) {
        int x, y, w, p;
        cin >> x >> y >> w >> p;
        x--; y--;
        edges[i] = {x, y, w, p};
        adj[x].push_back(i);
    }

    calculateSubtreeWeight(0);

    if (!adjustWeights(0, 0)) {
        cout << -1 << endl;
    } else {
        cout << n << endl;
        for (Edge edge : edges) {
            cout << edge.x + 1 << " " << edge.y + 1 << " " << edge.w << " " << (subtree_weights[edge.y] > edge.p ? subtree_weights[edge.y] : 0) << endl;
        }
    }

    return 0;
}