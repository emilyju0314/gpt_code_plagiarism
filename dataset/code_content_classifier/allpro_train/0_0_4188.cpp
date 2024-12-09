#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

struct Edge {
    int to, cap, flow, id;
};

vector<vector<Edge>> adj;
vector<int> level, ptr;

bool bfs(int source, int sink) {
    level.assign(adj.size(), -1);
    queue<int> q;
    q.push(source);
    level[source] = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (Edge &e : adj[v]) {
            if (level[e.to] == -1 && e.flow < e.cap) {
                level[e.to] = level[v] + 1;
                q.push(e.to);
            }
        }
    }

    return level[sink] != -1;
}

int dfs(int v, int flow, int sink) {
    if (v == sink || flow == 0) {
        return flow;
    }

    for (int &i = ptr[v]; i < adj[v].size(); i++) {
        Edge &e = adj[v][i];

        if (level[e.to] == level[v] + 1 && e.flow < e.cap) {
            int pushed = dfs(e.to, min(flow, e.cap - e.flow), sink);
            if (pushed > 0) {
                e.flow += pushed;
                adj[e.to][e.id].flow -= pushed; // Reverse edge
                return pushed;
            }
        }
    }

    return 0;
}

void addEdge(int u, int v, int cap, int id) {
    Edge forward = {v, cap, 0, id};
    Edge backward = {u, 0, 0, id};

    adj[u].push_back(forward);
    adj[v].push_back(backward);
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n);
    ptr.resize(n);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;

        addEdge(a, b, c, i);

        // We can assign the direction of the flow as 0 since it's undirected
        cout << "0" << endl;
    }

    return 0;
}