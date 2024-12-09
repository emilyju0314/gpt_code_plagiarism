#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isValidNervousSystem(int n, int m, vector<vector<int>>& connections) {
    vector<vector<int>> adjList(n+1);
    
    for(auto c: connections) {
        adjList[c[0]].push_back(c[1]);
        adjList[c[1]].push_back(c[0]);
    }
    
    for(int i = 1; i <= n; i++) {
        vector<bool> visited(n+1, false);
        queue<int> q;
        q.push(i);
        visited[i] = true;
        
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for(auto next: adjList[curr]) {
                if(!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        
        for(int j = 1; j <= n; j++) {
            if(!visited[j]) {
                return false;
            }
        }
    }
    
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> connections(m, vector<int>(2));
    for(int i = 0; i < m; i++) {
        cin >> connections[i][0] >> connections[i][1];
    }
    
    if(isValidNervousSystem(n, m, connections)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    
    return 0;
}