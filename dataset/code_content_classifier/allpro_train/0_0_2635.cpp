#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjList(n + 1);
    vector<int> indegree(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        indegree[b]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> order;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        order.push_back(curr);

        for (int neighbor : adjList[curr]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    if (order.size() != n) {
        cout << "-1" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            cout << order[i] << " ";
        }
        cout << endl;
    }

    return 0;
}