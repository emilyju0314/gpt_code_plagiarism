#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Node {
    int flavor;
    vector<int> children;
    int numNodes;
    vector<int> numCandies;
    vector<long long> cost;
};

vector<Node> tree;
vector<int> initialFlavors;
vector<int> flavorCosts;
vector<int> parent;

void dfs(int node) {
    tree[node].numNodes = 1;
    tree[node].numCandies.assign(flavorCosts.size(), 0);
    tree[node].numCandies[initialFlavors[node]] = 1;
    tree[node].cost.assign(flavorCosts.size(), 0);
    tree[node].cost[initialFlavors[node]] = flavorCosts[initialFlavors[node]-1];
    
    for(int child : tree[node].children) {
        dfs(child);
        tree[node].numNodes += tree[child].numNodes;
        for(int i = 1; i < flavorCosts.size(); i++) {
            tree[node].numCandies[i] += tree[child].numCandies[i];
            tree[node].cost[i] += tree[child].cost[i];
        }
    }
}

int main() {
    int n, m, q, C;
    cin >> n >> m >> q >> C;
    
    tree.resize(n+1);
    parent.resize(n+1);
    
    for(int i = 1; i <= n; i++) {
        Node node;
        cin >> node.flavor;
        initialFlavors.push_back(node.flavor);
        tree[i] = node;
    }
    
    for(int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        tree[p].children.push_back(i);
        parent[i] = p;
    }
    
    flavorCosts.push_back(0); // 0-based indexing
    for(int i = 0; i < m; i++) {
        int c;
        cin >> c;
        flavorCosts.push_back(c);
    }
    
    dfs(1);
    
    while(q--) {
        int t;
        cin >> t;
        
        if(t == 1) {
            int x, w;
            cin >> x >> w;
            int prevFlavor = initialFlavors[x-1];
            initialFlavors[x-1] = w;
            
            // Update the number of candies and costs in the subtree
            int curNode = x;
            while(curNode != 0) {
                tree[parent[curNode]].numCandies[prevFlavor] -= 1;
                tree[parent[curNode]].numCandies[w] += 1;
                tree[parent[curNode]].cost[prevFlavor] -= flavorCosts[prevFlavor];
                tree[parent[curNode]].cost[w] += flavorCosts[w];
                curNode = parent[curNode];
            }
        } else {
            int k;
            cin >> k;
            double error = 0;
            for(int i = 1; i <= n; i++) {
                error += pow(tree[i].cost[k] - floor(1.0 * tree[i].numCandies[k] * flavorCosts[k]), 2);
            }
            error /= n;
            cout << fixed << error << endl;
        }
    }
    
    return 0;
}