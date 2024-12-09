#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> red_edges, blue_edges;
vector<int> red_parent, blue_parent;

void dfs(int v, int parent, vector<vector<int>>& edges, vector<int>& parent_list) {
    parent_list[v] = parent;
    for (int u : edges[v]) {
        if (u != parent) {
            dfs(u, v, edges, parent_list);
        }
    }
}

int main() {
    int N, X, Y;
    cin >> N >> X >> Y;
    red_edges.resize(N+1);
    blue_edges.resize(N+1);
    red_parent.resize(N+1);
    blue_parent.resize(N+1);

    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        red_edges[a].push_back(b);
        red_edges[b].push_back(a);
    }

    for (int i = 0; i < N-1; i++) {
        int c, d;
        cin >> c >> d;
        blue_edges[c].push_back(d);
        blue_edges[d].push_back(c);
    }

    dfs(X, -1, red_edges, red_parent);
    dfs(Y, -1, blue_edges, blue_parent);

    vector<int> red_height(N+1, 0);
    vector<int> blue_height(N+1, 0);

    queue<int> red_queue, blue_queue;
    red_queue.push(X);
    blue_queue.push(Y);

    while (!red_queue.empty()) {
        int v = red_queue.front();
        red_queue.pop();
        if (v == Y) {
            cout << red_height[v] << endl;
            return 0;
        }
        for (int u : red_edges[v]) {
            if (u != red_parent[v]) {
                red_queue.push(u);
                red_height[u] = red_height[v] + 1;
            }
        }
    }

    while (!blue_queue.empty()) {
        int v = blue_queue.front();
        blue_queue.pop();
        if (v == X) {
            cout << blue_height[v] << endl;
            return 0;
        }
        for (int u : blue_edges[v]) {
            if (u != blue_parent[v]) {
                blue_queue.push(u);
                blue_height[u] = blue_height[v] + 1;
            }
        }
    }

    cout << "-1" << endl;

    return 0;
}