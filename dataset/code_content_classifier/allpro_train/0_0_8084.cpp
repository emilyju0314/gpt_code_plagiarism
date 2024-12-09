#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adjList(n+1);
    
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    
    vector<int> colors(n+1, -1);
    queue<int> q;
    
    for(int i = 1; i <= n; i++) {
        if(colors[i] == -1) {
            q.push(i);
            colors[i] = 0; // start with color 0 for the first horse in queue
            while(!q.empty()) {
                int curr = q.front();
                q.pop();
                for(int neighbor : adjList[curr]) {
                    if(colors[neighbor] == -1) {
                        colors[neighbor] = 1 - colors[curr]; // assign opposite color to neighbor
                        q.push(neighbor);
                    } else if(colors[neighbor] == colors[curr]) {
                        cout << "-1\n"; // not possible to divide the horses as required
                        return 0;
                    }
                }
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        cout << (colors[i] == 0 ? "0" : "1");
    }
    
    cout << endl;
    
    return 0;
}