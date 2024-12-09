#include <iostream>
#include <vector>

using namespace std;

bool hasCycle(vector<vector<int>>& adjList, vector<bool>& visited, int curr, int parent) {
    visited[curr] = true;
    
    for(int neighbor : adjList[curr]) {
        if (!visited[neighbor]) {
            if (hasCycle(adjList, visited, neighbor, curr)) {
                return true;
            }
        } else if (neighbor != parent) {
            return true;
        }
    }
    
    return false;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> adjList(N);
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; // Adjusting to 0-based indexing
        b--;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    
    vector<bool> visited(N, false);
    
    bool hasCycleFlag = false;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            if (hasCycle(adjList, visited, i, -1)) {
                hasCycleFlag = true;
                break;
            }
        }
    }
    
    if (hasCycleFlag) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}