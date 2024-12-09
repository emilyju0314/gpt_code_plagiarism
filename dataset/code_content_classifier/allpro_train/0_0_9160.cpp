#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
}

bool topologicalSort(vector<vector<int>>& adj, vector<int>& inDegree, vector<int>& result) {
    queue<int> q;
    for (int i = 0; i < inDegree.size(); i++) {
        if (inDegree[i] == 0) {
            q.push(i);
            result[i] = 1;
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
                result[v] = -result[u];
            }
        }
    }

    for (int i = 0; i < inDegree.size(); i++) {
        if (inDegree[i] > 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int N;
    cin >> N;

    vector<int> A(N), B(N);
    vector<vector<int>> adj(N);
    vector<int> inDegree(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] != -1) {
            addEdge(adj, A[i] - 1, i);
            inDegree[i]++;
        }
    }

    for (int i = 0; i < N; i++) {
        cin >> B[i];
        if (B[i] != -1) {
            addEdge(adj, B[i] - 1, i);
            inDegree[i]++;
        }
    }

    vector<int> result(N, 0);
    if (topologicalSort(adj, inDegree, result)) {
        cout << "POSSIBLE" << endl;
        for (int x : result) {
            cout << x << " ";
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}