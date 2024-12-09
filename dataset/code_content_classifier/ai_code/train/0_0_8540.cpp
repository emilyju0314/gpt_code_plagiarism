#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

vector<vector<pair<int, int>>> graph;
vector<int> parent;
vector<int> depth;
vector<int> weight;
vector<int> dp;
vector<int> subtreeSize;
vector<int> label;
vector<int> chainHead;
vector<int> chainId;
vector<int> posInBase;
vector<int> base;
vector<int> segTree;

void dfs(int node, int par, int dep) {
    parent[node] = par;
    depth[node] = dep;
    subtreeSize[node] = 1;
    
    for (auto nei : graph[node]) {
        if (nei.first != par) {
            weight[nei.first] = nei.second;
            dfs(nei.first, node, dep + 1);
            subtreeSize[node] += subtreeSize[nei.first];
        }
    }
}

int findHeavyChild(int node) {
    int maxChild = -1;
    int maxSize = -1;
    
    for (auto nei : graph[node]) {
        if (nei.first != parent[node] && subtreeSize[nei.first] > maxSize) {
            maxSize = subtreeSize[nei.first];
            maxChild = nei.first;
        }
    }
    
    return maxChild;
}

void hld(int node, int curChain, int& pos, int curLabel) {
    chainId[node] = curChain;
    label[node] = curLabel;
    posInBase[node] = pos;
    base[pos++] = node;
    
    int heavyChild = findHeavyChild(node);
    
    if (heavyChild != -1) {
        hld(heavyChild, curChain, pos, curLabel + 1);
    }
    
    for (auto nei : graph[node]) {
        if (nei.first != parent[node] && nei.first != heavyChild) {
            chainHead[curChain] = nei.first;
            hld(nei.first, curChain + 1, pos, 0);
        }
    }
}

int build(int left, int right, int index) {
    if (left == right) {
        return segTree[index] = dp[base[left]];
    }
    
    int mid = left + (right - left) / 2;
    
    return segTree[index] = min(build(left, mid, 2 * index + 1), build(mid + 1, right, 2 * index + 2));
}

int query(int left, int right, int qLeft, int qRight, int index) {
    if (left >= qLeft && right <= qRight) {
        return segTree[index];
    }
    
    if (left > qRight || right < qLeft) {
        return INF;
    }
    
    int mid = left + (right - left) / 2;
    
    return min(query(left, mid, qLeft, qRight, 2 * index + 1),
               query(mid + 1, right, qLeft, qRight, 2 * index + 2));
}

void update(int left, int right, int node, int val, int index) {
    if (left == right && left == node) {
        segTree[index] = val;
        return;
    }
    
    int mid = left + (right - left) / 2;
    
    if (node <= mid) {
        update(left, mid, node, val, 2 * index + 1);
    } else {
        update(mid + 1, right, node, val, 2 * index + 2);
    }
    
    segTree[index] = min(segTree[2 * index + 1], segTree[2 * index + 2]);
}

int main() {
    int n, q;
    cin >> n >> q;
    
    graph.resize(n);
    parent.resize(n);
    depth.resize(n);
    weight.resize(n);
    dp.resize(n);
    subtreeSize.resize(n);
    label.resize(n);
    chainHead.resize(n);
    chainId.resize(n);
    posInBase.resize(n);
    
    base.resize(n);
    segTree.resize(4 * n);
    
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }
    
    weight[0] = 0;
    dfs(0, -1, 0);
    hld(0, 0, 0, 0);
    
    vector<pair<int, pair<int, int>>> queries;
    
    for (int i = 0; i < 2 * n - 2; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        
        if (depth[u] < depth[v]) {
            swap(u, v);
        }
        
        queries.emplace_back(make_pair(1, make_pair(u, w)));
    }
    
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int i, w;
            cin >> i >> w;
            i--;
            int u = queries[i].second.first;
            int v = parent[u];
            
            if (dep[u] != dep[v] + 1) {
                swap(u, v);
            }

            update(0, n - 1, posInBase[u], w, 0);
        } else {
            int u, v;
            cin >> u >> v;
            u--; v--;
            
            int ans = INF;
            
            while (chainId[u] != chainId[v]) {
                if (depth[chainHead[chainId[u]]] < depth[chainHead[chainId[v]]) {
                    swap(u, v);
                }
                
                int curChain = chainId[u];
                ans = min(ans, query(0, n - 1, posInBase[chainHead[curChain]], posInBase[u], 0));
                u = parent[chainHead[curChain]];
            }
            
            if (posInBase[u] > posInBase[v]) {
                swap(u, v);
            }
            
            ans = min(ans, query(0, n - 1, posInBase[u], posInBase[v], 0));
            
            cout << ans << "\n";
        }
    }
    
    return 0;
}