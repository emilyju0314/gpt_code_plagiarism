#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }

        vector<vector<int>> graph(n + 1);
        vector<bool> visited(n + 1, false);

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int numFriends = 0;
        queue<int> q;
        q.push(1);
        visited[1] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            numFriends++;

            for (int i = 0; i < graph[curr].size(); i++) {
                int next = graph[curr][i];
                if (!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }

        cout << numFriends - 1 << endl;
    }

    return 0;
}