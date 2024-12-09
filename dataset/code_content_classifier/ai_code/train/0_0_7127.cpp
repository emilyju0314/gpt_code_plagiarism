#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> graph(n);
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    int k;
    cin >> k;
    
    unordered_map<int, int> visits;
    for(int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        
        vector<bool> visited(n, false);
        visited[a] = true;
        
        while(a != b) {
            if(!visited[a]) {
                visits[a]++;
                visited[a] = true;
            }
            a = graph[a][0];
        }
    }
    
    for(int i = 0; i < n-1; i++) {
        cout << visits[i] << " ";
    }
    
    return 0;
}