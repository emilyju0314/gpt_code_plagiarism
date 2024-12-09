#include <iostream>
#include <vector>
#include <queue>

#define MAXN 1000005

using namespace std;

int n, m;
vector<int> graph[MAXN];
int orders[MAXN];
bool visited[MAXN];

void bfs(int start, int end) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                orders[neighbor] = orders[current] + 1;
                q.push(neighbor);
            } else if (orders[neighbor] == 0 || orders[neighbor] > orders[current]) {
                orders[neighbor] = orders[current];
                q.push(neighbor);
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

    int s, t;
    cin >> s >> t;

    bfs(s, t);

    if (visited[t]) {
        cout << orders[t] << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}