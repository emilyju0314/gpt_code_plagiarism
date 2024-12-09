#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 1e5 + 5;

vector<int> adj[MAXN];
int distA[MAXN], distB[MAXN], cnt[MAXN];

void dfs(int u, int p, int dist[], int start) {
    dist[u] = start;
    for(int v : adj[u]) {
        if(v != p) {
            dfs(v, u, dist, start + 1);
        }
    }
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1, distA, 0);
    dfs(n, -1, distB, 0);

    int m;
    cin >> m;

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        int distDiff = abs(distA[x] - distB[y]);
        int mid = (distA[x] + distB[y] + distDiff) / 2;

        queue<int> q;
        q.push(1);
        while(!q.empty()) {
            int u = q.front();
            q.pop();

            if(distA[u] == mid && distB[u] == mid) {
                cnt[i]++;
            }

            for(int v : adj[u]) {
                q.push(v);
            }
        }

        cout << cnt[i] << endl;
    }

    return 0;
}