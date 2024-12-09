#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> adj(N + 1);
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> visited(N + 1, 0);
    vector<int> components;

    for(int i = 1; i <= N; i++) {
        if(visited[i] == 0) {
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            int count = 0;
            while(!q.empty()) {
                int curr = q.front();
                q.pop();
                count++;
                for(int neighbor : adj[curr]) {
                    if(visited[neighbor] == 0) {
                        visited[neighbor] = 1;
                        q.push(neighbor);
                    }
                }
            }
            components.push_back(count);
        }
    }

    int num_required = components.size();
    int num_edges = 0;
    for(auto c : components) {
        num_edges += c * (c - 1) / 2;
    }

    if(num_edges > K) {
        cout << "Impossible" << endl;
    } else {
        cout << num_required << endl;
    }

    return 0;
}