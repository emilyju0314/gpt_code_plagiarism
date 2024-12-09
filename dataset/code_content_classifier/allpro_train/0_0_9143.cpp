#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_VERTICES = 2e5 + 5;

int n, m, k;
vector<int> adj[MAX_VERTICES];
bool visited[MAX_VERTICES];
int startVertex[MAX_VERTICES];
int verticesPerClone;

void bfs(int start, int cloneNum) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int count = 1;
    startVertex[cloneNum] = start;
    
    while (!q.empty() && count < verticesPerClone) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
                count++;
                
                if (count <= verticesPerClone) {
                    startVertex[cloneNum] = v;
                }
            }
        }
    }
}

int main() {
    cin >> n >> m >> k;
    
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    verticesPerClone = (2 * n + k - 1) / k;
    
    for (int i = 0; i < k; i++) {
        fill(visited, visited + n + 1, false);
        bfs(startVertex[i] == 0 ? 1 : startVertex[i], i);
        
        cout << verticesPerClone << " ";
        for (int j = 1; j <= n; j++) {
            if (visited[j]) {
                cout << j << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}