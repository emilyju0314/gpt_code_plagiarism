#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N+1);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int Q;
    cin >> Q;

    vector<unordered_map<int, int>> colors(N+1);
    for (int i = 0; i < Q; i++) {
        int v, d, c;
        cin >> v >> d >> c;

        vector<int> dist(N+1, -1);
        queue<int> q;
        q.push(v);
        dist[v] = 0;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int nei : adj[cur]) {
                if (dist[nei] == -1 && dist[cur] + 1 <= d) {
                    dist[nei] = dist[cur] + 1;
                    q.push(nei);
                    colors[nei][i] = c;
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (colors[i].empty()) {
            cout << "0" << endl;
        } else {
            cout << colors[i].rbegin()->second << endl;
        }
    }

    return 0;
}