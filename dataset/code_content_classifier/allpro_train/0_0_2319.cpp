#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    vector<vector<int>> adj(N);
    for(int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    vector<int> dist(N, -1);
    for(int i = 0; i < N; i++) {
        if(S[i] == '1') {
            q.push(i);
            dist[i] = 0;
        }
    }

    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : adj[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == '1' && dist[i] % 2 == 1) {
            ans = max(ans, (dist[i]+1)/2);
        }
    }

    cout << ans << endl;

    return 0;
}