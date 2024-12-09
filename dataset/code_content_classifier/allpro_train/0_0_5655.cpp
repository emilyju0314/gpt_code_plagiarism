#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> actions(n);
    for (int i = 0; i < n; i++) {
        cin >> actions[i];
    }

    vector<vector<int>> adj(n + 1);
    vector<int> inDegree(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        inDegree[b]++;
    }

    vector<int> isInteresting(n, 0);
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (actions[i-1] == 1 && inDegree[i] == 0) {
            q.push(i);
            isInteresting[i-1] = 1;
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : adj[cur]) {
            inDegree[next]--;
            if (actions[next-1] == 2) {
                isInteresting[next-1] = 1;
            }
            if (inDegree[next] == 0) {
                q.push(next);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << isInteresting[i] << endl;
    }

    return 0;
}