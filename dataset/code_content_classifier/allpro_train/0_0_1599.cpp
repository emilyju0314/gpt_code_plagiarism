#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1); // adjacency list representation of the graph
    vector<int> indegree(n+1, 0); // count of incoming edges for each node

    for (int i = 0; i < m; i++) {
        int xi, yi;
        cin >> xi >> yi;
        graph[xi].push_back(yi);
        indegree[yi]++;
    }

    queue<int> q; // queue to perform topological sorting
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    int danger = 1;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor : graph[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
        danger *= 2; // multiply the danger by 2 for each chemical poured
    }

    cout << danger << endl;

    return 0;
}