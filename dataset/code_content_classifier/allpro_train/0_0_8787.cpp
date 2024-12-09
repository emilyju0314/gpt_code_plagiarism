#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<pair<int, int>>> adjList(N);
    for (int i = 0; i < M; i++) {
        int a, b, len;
        cin >> a >> b >> len;
        adjList[a].push_back({b, len});
        adjList[b].push_back({a, len});
    }

    vector<int> dist(N, -1);
    vector<int> numCities(N, 0);
    queue<int> q;
    dist[0] = 0;
    numCities[0] = 1;
    q.push(0);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (pair<int, int> neighbor : adjList[curr]) {
            int next = neighbor.first;
            int len = neighbor.second;
            
            if (dist[next] == -1 || dist[next] > dist[curr] + len) {
                dist[next] = dist[curr] + len;
                numCities[next] = numCities[curr] + 1;
                q.push(next);
            }
        }
    }

    cout << dist[N - 1] << endl;
    cout << numCities[N - 1] << endl;

    int curr = N - 1;
    vector<int> path;
    while (curr != 0) {
        path.push_back(curr);
        for (pair<int, int> neighbor : adjList[curr]) {
            int next = neighbor.first;
            int len = neighbor.second;
            if (dist[next] + len == dist[curr]) {
                curr = next;
                break;
            }
        }
    }
    path.push_back(0);

    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << " ";
    }

    return 0;
}