#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;
vector<int> values;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    values[start] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (values[v] == 0) {
                q.push(v);
                values[v] = 3 - values[u]; // Assign values such that the sum or product is a multiple of 3
            }
        }
    }
}

int main() {
    int N;
    cin >> N;

    adj.resize(N + 1);
    values.resize(N + 1, 0);

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(1);

    for (int i = 1; i <= N; i++) {
        cout << values[i] << " ";
    }
    
    return 0;
}