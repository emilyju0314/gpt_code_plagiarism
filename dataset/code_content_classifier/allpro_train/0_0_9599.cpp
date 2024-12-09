#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
public:
    Graph(int n) : adj_list(n), visited(n), parent(n), disc(n), low(n) {}

    void add_edge(int u, int v) {
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int bridges_count() {
        int count = 0;
        dfs(0, -1, count);
        return count;
    }

private:
    vector<vector<int>> adj_list;
    vector<bool> visited;
    vector<int> parent, disc, low;

    void dfs(int u, int p, int& count) {
        static int time = 0;
        visited[u] = true;
        disc[u] = low[u] = ++time;

        for (int v : adj_list[u]) {
            if (!visited[v]) {
                parent[v] = u;
                dfs(v, u, count);
                low[u] = min(low[u], low[v]);
                
                if (low[v] > disc[u]) {
                    count++;
                }
            } else if (v != p) {
                low[u] = min(low[u], disc[v]);
            }
        }
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    Graph g(N);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        g.add_edge(a-1, b-1);
    }

    cout << g.bridges_count() << endl;

    return 0;
}