#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
public:
    int color;
    int blueChildren;
    int redChildren;
    
    Node(int col) : color(col), blueChildren(0), redChildren(0) {}
};

vector<vector<int>> adjList;
vector<Node> nodes;

void dfs(int u, int parent) {
    for (int v : adjList[u]) {
        if (v != parent) {
            dfs(v, u);
            if (nodes[v].color == 1) nodes[u].blueChildren++;
            else nodes[u].redChildren++;
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    
    adjList.resize(n+1);
    nodes.resize(n+1, Node(-1));
    
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    for (int i = 1; i <= n; i++) {
        cin >> nodes[i].color;
    }
    
    dfs(1, -1);
    
    int q;
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int v;
            cin >> v;
            int totalBlue = nodes[v].blueChildren;
            int totalRed = nodes[v].redChildren;
            if (nodes[v].color == 1) totalBlue++;
            else totalRed++;
            if (totalBlue - totalRed >= k) cout << "1" << endl;
            else cout << "0" << endl;
        } else if (type == 2) {
            int v, c;
            cin >> v >> c;
            if (nodes[v].color == 1 && c == 0) nodes[v].blueChildren--;
            if (nodes[v].color == 0 && c == 1) nodes[v].blueChildren++;
            nodes[v].color = c;
        } else if (type == 3) {
            cin >> k;
        }
    }
    
    return 0;
}