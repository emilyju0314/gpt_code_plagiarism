#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int MAXN = 101;
int n;
vector<int> graph[MAXN];
int dist[MAXN];

void bfs(int start) {
    fill(dist, dist + n + 1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int u, k;
        cin >> u >> k;
        for (int j = 0; j < k; j++) {
            int v;
            cin >> v;
            graph[u].push_back(v);
        }
    }

    bfs(1);

    for (int i = 1; i <= n; i++) {
        cout << i << " " << dist[i] << endl;
    }

    return 0;
}