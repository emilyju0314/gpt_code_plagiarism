#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 3005;

vector<int> adj[MAXN], adj_rev[MAXN];
bool visited[MAXN];
bool visited2[MAXN][MAXN];
int dist1[MAXN], dist2[MAXN][MAXN];

void bfs(int start, int dist[], vector<int> adj[]){
    memset(visited, false, sizeof(visited));

    queue<int> q;
    q.push(start);
    visited[start] = true;
    dist[start] = 0;

    while (!q.empty()){
        int u = q.front();
        q.pop();

        for (int v : adj[u]){
            if (!visited[v]){
                visited[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int s1, t1, l1, s2, t2, l2;
    cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;

    bfs(s1, dist1, adj);
    for (int i = 1; i <= n; i++){
        bfs(i, dist2[i], adj);
    }

    int ans = m+1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (dist1[i] <= l1 && dist2[i][j] <= l2 && dist1[j] <= l1){
                ans = min(ans, m - adj[i].size() - adj[j].size());
            }
        }
    }

    cout << (ans == m+1 ? -1 : ans) << endl;

    return 0;
}