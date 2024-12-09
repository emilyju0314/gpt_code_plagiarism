#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 1e9;
const int MAXN = 3005;

int n, m;
vector<int> graph[MAXN];
int dist[MAXN][MAXN];

void bfs(int source) {
    queue<int> q;
    q.push(source);
    dist[source][source] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (dist[source][v] == INF) {
                dist[source][v] = dist[source][u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = INF;
        }
    }

    for (int i = 1; i <= n; i++) {
        bfs(i);
    }

    int max_dist = 0;
    vector<int> answer(4);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] != INF) {
                for (int s = 1; s <= n; s++) {
                    for (int t = 1; t <= n; t++) {
                        if (dist[s][i] != INF && dist[j][t] != INF) {
                            int total_dist = dist[i][j] + dist[s][i] + dist[j][t];
                            if (total_dist > max_dist) {
                                max_dist = total_dist;
                                answer[0] = s;
                                answer[1] = i;
                                answer[2] = j;
                                answer[3] = t;
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}