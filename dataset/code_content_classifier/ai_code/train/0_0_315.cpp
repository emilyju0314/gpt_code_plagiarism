#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 5;

vector<int> adj[MAX_N];
int dist_u[MAX_N], dist_v[MAX_N];

void dfs(int node, int parent, int* dist) {
    dist[node] = dist[parent] + 1;
    for (int child : adj[node]) {
        if (child != parent) {
            dfs(child, node, dist);
        }
    }
}

int main() {
    int N, u, v;
    cin >> N >> u >> v;

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dist_u[0] = dist_v[0] = -1;
    dfs(u, 0, dist_u);
    dfs(v, 0, dist_v);

    int farthest = -1;
    for (int i = 1; i <= N; i++) {
        if (dist_u[i] > dist_u[farthest] && dist_v[i] < dist_v[i]) {
            farthest = i;
        }
    }

    int distance = dist_u[farthest];
    int num_moves = distance / 2;

    cout << num_moves << endl;

    return 0;
}