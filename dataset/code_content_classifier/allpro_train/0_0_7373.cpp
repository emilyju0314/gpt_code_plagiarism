#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 3005;

vector<int> adj[MAXN];
int dist[MAXN];
bool visited[MAXN];

void bfs(int start) {
    memset(visited, false, sizeof(visited));
    memset(dist, -1, sizeof(dist));

    queue<int> q;
    q.push(start);
    dist[start] = 0;
    visited[start] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int next : adj[curr]) {
            if (!visited[next]) {
                visited[next] = true;
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int xi, yi;
        cin >> xi >> yi;
        adj[xi].push_back(yi);
        adj[yi].push_back(xi);
    }

    for (int i = 1; i <= n; i++) {
        bfs(i);
        int min_dist = n;
        for (int j = 1; j <= n; j++) {
            min_dist = min(min_dist, dist[j]);
        }
        cout << min_dist << " ";
    }

    return 0;
}