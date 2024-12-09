#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 2000;
vector<int> graph[MAXN];
int color[MAXN];
bool visited[MAXN];

void bfs(int start, int state) {
    queue<int> q;
    q.push(start);
    color[start] = state;
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                color[neighbor] = state;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;

        for (int j = 0; j < n; j++) {
            graph[j].clear();
        }

        memset(visited, false, sizeof(visited));
        memset(color, 0, sizeof(color));

        for (int j = 0; j < m; j++) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;

            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        int state = 1;
        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                bfs(j, state);
                state = 3 - state;
            }
        }

        cout << 2 << endl;
        for (int j = 0; j < n; j++) {
            cout << color[j] << " ";
        }
        cout << endl;
    }

    return 0;
}