#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int findMinEdgesToDelete(int N, vector<pair<int, int>>& edges, int a, int b) {
    unordered_map<int, vector<int>> adjList;
    for(auto& edge : edges) {
        adjList[edge.first].push_back(edge.second);
        adjList[edge.second].push_back(edge.first);
    }

    vector<int> distances(N+1, -1);
    queue<int> q;
    q.push(a);
    distances[a] = 0;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int neighbor : adjList[node]) {
            if(distances[neighbor] == -1) {
                distances[neighbor] = distances[node] + 1;
                q.push(neighbor);
            }
        }
    }

    return distances[b];
}

int main() {
    int N, Q;
    cin >> N;

    vector<pair<int, int>> edges(N);
    for(int i = 0; i < N; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    cin >> Q;

    for(int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;

        cout << findMinEdgesToDelete(N, edges, a, b) << endl;
    }

    return 0;
}