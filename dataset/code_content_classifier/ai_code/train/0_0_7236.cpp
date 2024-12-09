#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

vector<int> adj[N];
int dist[N][N], parent[N];

void bfs(int s, int n) {
    for (int i = 1; i <= n; i++) {
        dist[s][i] = 1e9;
        parent[i] = -1;
    }
    queue<int> q;
    q.push(s);
    dist[s][s] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (dist[s][u] == 1e9) {
                dist[s][u] = dist[s][v]+1;
                parent[u] = v;
                q.push(u);
            }
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> cities(2*k);
    for (int i = 0; i < 2*k; i++) {
        cin >> cities[i];
    }

    for (int i = 0; i < 2*k; i++) {
        bfs(cities[i], n);
    }

    int best_city = cities[0];
    for (int i = 1; i < 2*k; i++) {
        if (dist[best_city][cities[i]] > dist[best_city][cities[i-1]]) {
            best_city = cities[i];
        }
    }

    cout << "1\n" << best_city << endl;

    for (int i = 0; i < k; i++) {
        cout << cities[2*i] << " " << cities[2*i+1] << " " << best_city << endl;
    }

    return 0;
}