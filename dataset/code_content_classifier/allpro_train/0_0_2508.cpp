#include <iostream>
#include <vector>

using namespace std;

bool canBeSatisfied(int n, int u, int v, vector<pair<int, int>> edges) {
    vector<bool> visited(n, false);
    
    int current = u;
    while(current != v) {
        visited[current-1] = true;
        bool nextFound = false;
        
        for(auto edge : edges) {
            if(edge.first == current && !visited[edge.second-1]) {
                current = edge.second;
                nextFound = true;
                break;
            } else if(edge.second == current && !visited[edge.first-1]) {
                current = edge.first;
                nextFound = true;
                break;
            }
        }
        
        if(!nextFound) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int n, u, v;
    cin >> n >> u >> v;
    
    vector<pair<int, int>> edges;
    
    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        edges.push_back(make_pair(a, b));
    }
    
    if(canBeSatisfied(n, u, v, edges)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}