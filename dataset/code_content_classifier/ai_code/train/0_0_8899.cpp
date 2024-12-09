#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100001];
int colors[100001];
int fennecCount = 0;
int snukeCount = 0;

void dfs(int node, int parent, int color) {
    colors[node] = color;
    if(color == 1) {
        fennecCount++;
    } else {
        snukeCount++;
    }
    for(int next : adj[node]) {
        if(next != parent) {
            dfs(next, node, 1 - color);
        }
    }
}

int main() {
    int N;
    cin >> N;
    
    for(int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1, 0, 1);
    
    if(fennecCount > snukeCount) {
        cout << "Fennec";
    } else {
        cout << "Snuke";
    }
    
    return 0;
}