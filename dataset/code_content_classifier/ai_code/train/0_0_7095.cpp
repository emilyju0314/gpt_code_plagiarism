#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> inDegree(N, 0);
    vector<vector<int>> adj(N);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        inDegree[b]++;
    }

    vector<int> T(N, 0);
    queue<int> q;

    for (int i = 0; i < N; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
            T[i] = 0;
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            T[v] = max(T[v], T[u] + 1);
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    int cost = INT_MAX;
    for (int i = 0; i < N; i++) {
        cost = min(cost, T[i]);
    }

    cout << count(T.begin(), T.end(), cost) << " " << cost << endl;
    for (int i = 0; i < N; i++) {
        if (T[i] == cost) {
            cout << i << " ";
        }
    }

    return 0;
}