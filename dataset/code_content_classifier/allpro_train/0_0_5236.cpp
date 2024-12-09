#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> adjacencyList;
unordered_map<int, int> visited;
vector<pair<int, int>> cables;

bool dfs(int node, int parent, int color) {
    visited[node] = color;
  
    for(int neighbor : adjacencyList[node]) {
        if(neighbor == parent) continue;
        
        if(visited.count(neighbor)) {
            if(visited[neighbor] == color) return false;
        } else {
            if(!dfs(neighbor, node, 1 - color)) return false;
        }
    }
  
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    adjacencyList.resize(n + 1);
  
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        
        adjacencyList[a].push_back(b);
        adjacencyList[b].push_back(a);

        cables.push_back({a, b});
    }
    
    vector<pair<int, int>> extraCables;
    
    for(int i = 1; i <= n; i++) {
        if(!visited.count(i)) {
            if(!dfs(i, -1, 0)) {
                int dummy = n + 1;
                
                adjacencyList[dummy].push_back(i);
                adjacencyList[i].push_back(dummy);
                extraCables.push_back({dummy, i});
                n++;
            }
        }
    }
    
    cout << (m + extraCables.size()) << endl;
    
    for(auto& cable : cables) {
        cout << cable.first << " " << cable.second << endl;
    }
    
    for(auto& cable : extraCables) {
        cout << cable.first << " " << cable.second << endl;
    }
  
  return 0;
}