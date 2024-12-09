#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;
const int MAXN = 305;

int n, m, s, t;
vector<pair<int, int>> adj[MAXN];
int capacity[MAXN][MAXN], flow[MAXN][MAXN];
vector<int> parent;

int bfs() {
    parent.assign(MAXN, -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int cur_flow = q.front().second;
        q.pop();

        for (auto next : adj[cur]) {
            int next_node = next.first;
            int next_capacity = capacity[cur][next_node] - flow[cur][next_node];

            if (next_capacity > 0 && parent[next_node] == -1) {
                parent[next_node] = cur;
                int new_flow = min(cur_flow, next_capacity);
                if (next_node == t) {
                    return new_flow;
                }
                q.push({next_node, new_flow});
            }
        }
    }

    return 0;
}

int edmondsKarp() {
    int max_flow = 0;
    int new_flow;

    while (new_flow = bfs()) {
        max_flow += new_flow;
        int current = t;
        while (current != s) {
            int prev = parent[current];
            flow[prev][current] += new_flow;
            flow[current][prev] -= new_flow;
            current = prev;
        }
    }

    return max_flow;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back({y, 1});
        capacity[x][y] = 1;
        adj[y].push_back({x, 0});
        capacity[y][x] = 0;
    }

    cin >> s >> t;

    int max_flow = edmondsKarp();
    cout << max_flow << endl;

    vector<int> reversed_roads;
    for (int i = 1; i <= n; i++) {
        for (auto next : adj[i]) {
            int next_node = next.first;
            if (flow[i][next_node] > 0 && flow[next_node][i] == 0) {
                reversed_roads.push_back(i);
            }
        }
    }

    cout << reversed_roads.size() << endl;
    for (int road : reversed_roads) {
        cout << road << endl;
    }

    return 0;
}