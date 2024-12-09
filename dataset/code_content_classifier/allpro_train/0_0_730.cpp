#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1); // adjacency list representation of the graph
    vector<int> indegree(n + 1, 0); // to keep track of indegree of each vertex

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++; // increment the indegree of vertex b
    }

    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) {
            q.push(i); // vertex with 0 indegree is a starting point
        }
    }

    int teleportPipes = 0;
    while(!q.empty()) {
        int current = q.front();
        q.pop();
        
        for(int neighbor : graph[current]) {
            indegree[neighbor]--;
            if(indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }

        teleportPipes++;
    }

    cout << n - teleportPipes << endl; // total cities minus minimum number of teleportation pipes

    return 0;
}