#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Edge {
    int to;
    bool visited;
};

vector<int> generate_permutation(int n, vector<vector<int>>& edges) {
    vector<int> permutation(n, 0);
    vector<vector<Edge>> tree(n);
    vector<int> in_degree(n, 0);
    
    for (int i = 0; i < n - 1; i++) {
        int v, w;
        cin >> v >> w;
        v--; w--;
        edges.push_back({v, w});
        tree[v].push_back({w, false});
        tree[w].push_back({v, false});
        in_degree[v]++;
        in_degree[w]++;
    }
    
    stack<int> s;
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 1) {
            s.push(i);
        }
    }
    
    int idx = 0;
    while (!s.empty()) {
        int v = s.top();
        s.pop();
        permutation[idx++] = v + 1;
        
        for (Edge& e : tree[v]) {
            if (!e.visited) {
                e.visited = true;
                in_degree[e.to]--;
                if (in_degree[e.to] == 1) {
                    s.push(e.to);
                }
            }
        }
    }
    
    if (idx != n) {
        return vector<int>();
    } else {
        return permutation;
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> edges;
    vector<int> permutation = generate_permutation(n, edges);
    
    if (permutation.empty()) {
        cout << "-1" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            cout << permutation[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}