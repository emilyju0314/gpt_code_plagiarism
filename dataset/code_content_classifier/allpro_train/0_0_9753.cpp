#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adjList;
int n;
int ans = 0;

void dfs(int u, int p) {
    int children = adjList[u].size();
    for(int i = 0; i < children; i++) {
        int v = adjList[u][i];
        if(v != p) {
            if(children < 4) {
                ans++;
            }
            dfs(v, u);
        }
    }
}

int main() {
    cin >> n;
    adjList.resize(n+1);
    
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    dfs(1, 0);
    
    cout << ans << endl;
    
    return 0;
}