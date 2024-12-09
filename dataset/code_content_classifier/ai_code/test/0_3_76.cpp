#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adjList(N + 1);
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for(int i = 1; i <= N; i++) {
        if(adjList[i].size() >= 4) {
            cout << i << " ";
            unordered_set<int> friends;
            for(int v : adjList[i]) {
                friends.insert(v);
            }
            for(int j = 1; j <= N; j++) {
                if(j == i) continue;
                
                if(friends.find(j) == friends.end()) {
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