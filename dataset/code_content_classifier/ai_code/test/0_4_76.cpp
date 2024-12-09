#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N+1);
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= N; i++) {
        unordered_set<int> friends;
        for(auto& friend : adj[i]) {
            friends.insert(friend);
        }
        if(friends.size() >= 4) {
            cout << i << " ";
            for(int j = 1; j <= N; j++) {
                if(j != i && friends.find(j) == friends.end()) {
                    cout << j << " ";
                }
                if(j != i && friends.find(j) == friends.end()) {
                    cout << j << " ";
                }
            }
            cout << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}