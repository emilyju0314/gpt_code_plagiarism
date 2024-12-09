#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Node structure for Disjoint Set Union
struct Node {
    int parent;
    int rank;
};

// Function to find the parent of a node using path compression technique
int findParent(int u, vector<Node>& dsu) {
    if (dsu[u].parent != u)
        dsu[u].parent = findParent(dsu[u].parent, dsu);
    return dsu[u].parent;
}

// Function to perform union operation on two nodes
void unionNodes(int u, int v, vector<Node>& dsu) {
    int pu = findParent(u, dsu);
    int pv = findParent(v, dsu);
    
    if (dsu[pu].rank < dsu[pv].rank)
        dsu[pu].parent = pv;
    else if (dsu[pu].rank > dsu[pv].rank)
        dsu[pv].parent = pu;
    else {
        dsu[pv].parent = pu;
        dsu[pu].rank++;
    }
}

// Comparator function for sorting edges
bool compareEdges(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
    return get<2>(a) < get<2>(b);
}

int main() {
    int n, m;
    
    while (cin >> n >> m) {
        if (n == 0 && m == 0)
            break;
        
        vector<tuple<int, int, int>> edges;
        for (int i = 0; i < m; i++) {
            int u, v, c;
            cin >> u >> v >> c;
            edges.push_back(make_tuple(u, v, c));
        }
        
        sort(edges.begin(), edges.end(), compareEdges);
        
        vector<Node> dsu(n+1);
        for (int i = 1; i <= n; i++) {
            dsu[i].parent = i;
            dsu[i].rank = 0;
        }
        
        int median = 0;
        int cnt = 0;
        for (auto edge : edges) {
            int u = get<0>(edge);
            int v = get<1>(edge);
            int c = get<2>(edge);
            
            if (findParent(u, dsu) != findParent(v, dsu)) {
                unionNodes(u, v, dsu);
                cnt++;
                
                if (cnt == n/2) {
                    median = c;
                    break;
                }
            }
        }
        
        cout << median << endl;
    }
    
    return 0;
}