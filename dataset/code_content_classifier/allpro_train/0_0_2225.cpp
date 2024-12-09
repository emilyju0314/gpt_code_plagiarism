#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    
    int min_steps = n;
    vector<int> selected_steps;
    
    for(int i = 1; i <= n; i++) {
        vector<int> friends;
        for(int j = 1; j <= n; j++) {
            if(adj[i][j] == 1) {
                friends.push_back(j);
            }
        }
        
        int steps = 0;
        vector<int> selected;
        for(int j = 1; j <= n; j++) {
            if(i != j && adj[i][j] == 0) {
                bool pair_found = false;
                for(int k = 0; k < friends.size(); k++) {
                    for(int l = k + 1; l < friends.size(); l++) {
                        if(adj[friends[k]][friends[l]] == 0) {
                            adj[friends[k]][friends[l]] = 1;
                            adj[friends[l]][friends[k]] = 1;
                            pair_found = true;
                            selected.push_back(i);
                            steps++;
                        }
                        if(pair_found) break;
                    }
                    if(pair_found) break;
                }
            }
        }
        
        if(steps < min_steps) {
            min_steps = steps;
            selected_steps = selected;
        }
    }
    
    cout << min_steps << endl;
    for(int i = 0; i < min_steps; i++) {
        cout << selected_steps[i] << " ";
    }
    
    return 0;
}