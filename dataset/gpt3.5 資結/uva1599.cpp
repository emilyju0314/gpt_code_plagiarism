#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 1e5 + 5;

int n, m;
vector<int> graph[MAXN];

void bfs(int start, vector<int>& dist) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int next : graph[curr]) {
            if (dist[next] == -1) {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }
}

int main() {
    cin >> n >> m;

    // Build the graph
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> dist1(n, -1); // distance from node 1
    vector<int> distn(n, -1); // distance from node n

    bfs(1, dist1);
    bfs(n, distn);

    int shortest_path = dist1[n];

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (dist1[i] + distn[i] == shortest_path) {
            ans.push_back(i);
        }
    }

    cout << shortest_path << endl;
    for (int i : ans) {
        cout << i << " ";
    }

    return 0;
}