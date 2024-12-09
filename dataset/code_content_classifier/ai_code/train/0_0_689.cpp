#include <iostream>
#include <vector>

using namespace std;

bool hasCycleUtil(vector<vector<int>>& adjList, vector<bool>& visited, vector<bool>& inStack, int u) {
    visited[u] = true;
    inStack[u] = true;
    
    for(int v : adjList[u]) {
        if(!visited[v]) {
            if(hasCycleUtil(adjList, visited, inStack, v))
                return true;
        } else if(inStack[v]) {
            return true; // Cycle found
        }
    }
    
    inStack[u] = false;
    return false;
}

bool hasCycle(vector<vector<int>>& adjList, int V) {
    vector<bool> visited(V, false);
    vector<bool> inStack(V, false);
    
    for(int i = 0; i < V; ++i) {
        if(!visited[i] && hasCycleUtil(adjList, visited, inStack, i))
            return true;
    }
    
    return false;
}

int main() {
    int V, E;
    cin >> V >> E;
    
    vector<vector<int>> adjList(V);
    
    for(int i = 0; i < E; ++i) {
        int source, target;
        cin >> source >> target;
        adjList[source].push_back(target);
    }
    
    if(hasCycle(adjList, V))
        cout << "1\n";
    else
        cout << "0\n";
    
    return 0;
}