#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool topologicalSort(vector<vector<int>>& graph, vector<int>& indegree, int N) {
    vector<int> order;
    queue<int> q;

    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : graph[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    return order.size() == N;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N+1);
    vector<int> indegree(N+1, 0);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }

    if (topologicalSort(graph, indegree, N)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}