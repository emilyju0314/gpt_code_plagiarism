#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, q;
vector<int> parent;
vector<vector<int>> children;
vector<int> depth;
vector<int> maxDepth;

void dfs(int node, int par, int dep) {
    parent[node] = par;
    depth[node] = dep;
    
    for(int child : children[node]) {
        if(child != par) {
            dfs(child, node, dep + 1);
        }
    }
}

void preprocess() {
    parent.resize(n + 1);
    children.resize(n + 1);
    depth.resize(n + 1);
    maxDepth.resize(n + 1);
    
    for(int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        children[p].push_back(i);
    }
    
    dfs(1, -1, 0);
    
    for(int i = 1; i <= n; i++) {
        maxDepth[depth[i]] = i;
    }
}

int findLCA(int a, int b) {
    while(a != b) {
        if(depth[a] > depth[b]) {
            a = parent[a];
        } else {
            b = parent[b];
        }
    }
    return a;
}

int findMaxLength(int a, int b, int c) {
    int fa = findLCA(a, b);
    int fb = findLCA(b, c);
    int fc = findLCA(c, a);
    
    int ans = max(depth[fa], max(depth[fb], depth[fc]));
    
    int diam1 = depth[fa] + depth[fb] - 2 * depth[findLCA(fa, fb)];
    int diam2 = depth[fb] + depth[fc] - 2 * depth[findLCA(fb, fc)];
    int diam3 = depth[fc] + depth[fa] - 2 * depth[findLCA(fc, fa)];
    
    return max(ans, max(diam1, max(diam2, diam3)) + 1);
}

int main() {
    cin >> n >> q;
    
    preprocess();
    
    for(int i = 0; i < q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        
        cout << findMaxLength(a, b, c) << endl;
    }
    
    return 0;
}